/*
 * Copyright (C) 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include <gazebo/gazebo.hh>
#include <ignition/math.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdio.h>
#include <random>
#include <iostream>

namespace gazebo
{
  class AnimatedBox : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->model = _parent;

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 200 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("test", 211.02, true));

        gazebo::common::PoseKeyFrame *key;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1.0, 1.0);

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(46, -48, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        // set waypoint location after 16 seconds

        double x = dis(gen);
        double y = dis(gen);

        std::cout << x << " " << y << std::endl;
        key = anim->CreateKeyFrame(17.32);
        key->Translation(ignition::math::Vector3d(-2.5 + x, -48 + y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        x = dis(gen);
        y = dis(gen);
        std::cout << x << " " << y << std::endl;
        key = anim->CreateKeyFrame(19.63);
        key->Translation(ignition::math::Vector3d(-6.5 + x, -42.9 + y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.37));

        x = dis(gen);
        y = dis(gen);
        std::cout << x << " " << y << std::endl;
        key = anim->CreateKeyFrame(34.65);
        key->Translation(ignition::math::Vector3d(-14.9 + x, -1.67 + y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.37));


        x = dis(gen);
        y = dis(gen);
        std::cout << x << " " << y << std::endl;
        key = anim->CreateKeyFrame(39.175);
        key->Translation(ignition::math::Vector3d(-19 + x, 3.16 + y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));


        x = dis(gen);
        y = dis(gen);

        std::cout << x << " " << y << std::endl;
        key = anim->CreateKeyFrame(41.315);
        key->Translation(ignition::math::Vector3d(-21 + x, 3.16 + y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(49.885);
        key->Translation(ignition::math::Vector3d(-9, 3.16, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));


        key = anim->CreateKeyFrame(169.9);
        key->Translation(ignition::math::Vector3d(-9 , 3.16, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        x = dis(gen);
        y = dis(gen);

        std::cout << x << " " << y << std::endl;
        key = anim->CreateKeyFrame(172.61);
        key->Translation(ignition::math::Vector3d(-12.8 + x, 3.16 + y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        x = dis(gen);
        y = dis(gen);

        std::cout << x << " " << y << std::endl;
        key = anim->CreateKeyFrame(176.37);
        key->Translation(ignition::math::Vector3d(-14.9 + x, -1.67 + y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.75));

        x = dis(gen);
        y = dis(gen);

        std::cout << x << " " << y << std::endl;
        key = anim->CreateKeyFrame(191.39);
        key->Translation(ignition::math::Vector3d(-6.5 + x, -42.9 + y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.75));

        x = dis(gen);
        y = dis(gen);
        
        std::cout << x << " " << y << std::endl;
        key = anim->CreateKeyFrame(193.7);
        key->Translation(ignition::math::Vector3d(-2.5 + x, -48 + y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        key = anim->CreateKeyFrame(211.02);
        key->Translation(ignition::math::Vector3d(46, -48, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));



        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedBox)
}
