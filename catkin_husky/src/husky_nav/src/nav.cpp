/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%

#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <math.h>
#include <vector>
#include <utility>

// %EndTag(MSG_HEADER)%

#include <sstream>

static const std::vector<std::pair<double, double>> goalsVector = { {7.82, 31.4}, {-2.4, 38.6}, {-11.8, 30.5}, {-8.6, 25.6}, {-19.46, 14.2}, {11.0, -1.3}, {14.0, 9.0}}; 
double ang_vel = 0.0;
double vel = 0.8;
double eps = 2.0;
double xState = 13.0;
double yState = 9.0;
double xGoal = 7.82;
double yGoal = 31.4;
double z_orientation = 0.0;
double max_rotation = M_PI / 4;
int goalIndex = 0;


void hstateCallback(const nav_msgs::Odometry msg)
{
    xState = msg.pose.pose.position.x;
    yState = msg.pose.pose.position.y;
    /* transform quaternion to yaw */
    double siny = 2.0 * (msg.pose.pose.orientation.w * msg.pose.pose.orientation.z + msg.pose.pose.orientation.x * msg.pose.pose.orientation.y);
    double cosy = 1.0 - 2.0 * (msg.pose.pose.orientation.y * msg.pose.pose.orientation.y + msg.pose.pose.orientation.z * msg.pose.pose.orientation.z);  
    z_orientation = atan2(siny, cosy);
    ROS_INFO("G_POS : [%f, %f]", xGoal, yGoal);
    ROS_INFO("R_POS : [%f, %f]", xState, yState);
    ROS_INFO("Z_ORIENTATION : [%f]", z_orientation);
}
  
void laserCallback(const sensor_msgs::LaserScan msg)
{
  int size((msg.angle_max - msg.angle_min) / msg.angle_increment);
  int nearest((msg.angle_min - M_PI / 2) * msg.angle_increment);
  double dist {sqrt((xGoal - xState) * (xGoal - xState) + (yGoal - yState) * (yGoal - yState))};
  double maxD {3.0};

  for (int i = (size / 2) - (M_PI/(2* msg.angle_increment)); i <= size + (M_PI/(2* msg.angle_increment)); i++)
    if (msg.ranges[i] < msg.ranges[nearest] && msg.ranges[i] > 0.5)
      nearest = i;
  if (msg.ranges[nearest] > 5.0 || (msg.ranges[nearest] > dist))
  {
    if (xGoal > xState)
      ang_vel = atan((yGoal - yState)/(xGoal - xState));
    else
    {
      if (yGoal > yState)
        ang_vel = M_PI + atan((yGoal - yState)/(xGoal - xState));
      else
        ang_vel = -M_PI + atan((yGoal - yState)/(xGoal - xState));
    }
    ROS_INFO("ANG_VEL : [%f]", ang_vel);
    ang_vel = ang_vel - z_orientation;
    if (ang_vel > (M_PI))
      ang_vel = ang_vel - (2 * M_PI);
    else if (ang_vel < (M_PI))
      ang_vel = ang_vel + (2 * M_PI);
  }
  else if (msg.ranges[nearest] < maxD)
  {
    ang_vel = (M_PI/2) * (maxD - msg.ranges[nearest]) / maxD;
    if (nearest > ((size/2) - 1))
      ang_vel = -ang_vel ;
  }
  if (dist <= vel)
    vel = dist;
  else
    vel = 0.8;
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
// %Tag(INIT)%
  ros::init(argc, argv, "nav");
// %EndTag(INIT)%

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be autXomatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */

// %Tag(PUBLISHERS)
  ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/husky_velocity_controller/cmd_vel", 1);
// %EndTag(PUBLISHERS)%

// %Tag(SUBSCRIBER)%
  ros::Subscriber hstate_sub = n.subscribe<nav_msgs::Odometry>("/ground_truth/husky_state", 1, &hstateCallback);
  ros::Subscriber laser_sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1, &laserCallback);
// %EndTag(SUBSCRIBER)%



// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(8);
// %EndTag(LOOP_RATE)%

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
// %Tag(ROS_OK)%
  while (ros::ok())
  {
// %EndTag(ROS_OK)%
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    
// %Tag(FILL_MESSAGE)%*
    geometry_msgs::Twist msg;

    msg.linear.x = vel;
    
    msg.angular.z = ang_vel;

    if (msg.angular.z > (M_PI))
      msg.angular.z = msg.angular.z - (2 * M_PI);
    else if (msg.angular.z < (M_PI))
      msg.angular.z = msg.angular.z + (2 * M_PI);

    if (msg.angular.z > max_rotation)
      msg.angular.z = max_rotation;
    else if (msg.angular.z < -max_rotation)
      msg.angular.z = -max_rotation;


// %EndTag(FILL_MESSAGE)%

// %Tag(ROSCONSOLE)%

    //ROS_INFO("%s", msg.data.c_str());
    //ROS_INFO_STREAM("Subscriber velocities:"<<" linear="<<"2.0");
// %EndTag(ROSCONSOLE)%

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
// %Tag(PUBLISH)%
    cmd_vel_pub.publish(msg);
// %EndTag(PUBLISH)%
    if (abs(xGoal - xState) <= eps && abs(yGoal - yState) <= eps)
    {
      goalIndex = (goalIndex + 1) % goalsVector.size();
      xGoal = goalsVector[goalIndex].first;
      yGoal = goalsVector[goalIndex].second;
      vel = 0.8;
    }

// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();
// %EndTag(RATE_SLEEP)%
  }


  return 0;
}
// %EndTag(FULLTEXT)%
