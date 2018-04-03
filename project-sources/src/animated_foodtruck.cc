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

namespace gazebo
{
  class AnimatedFoodTruck : public ModelPlugin
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
              new gazebo::common::PoseAnimation("animated_foodtruck", 190.84, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(21, -48.35, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        // set waypoint location
        key = anim->CreateKeyFrame(8.167);
        key->Translation(ignition::math::Vector3d(1.87, -48.35, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(11.16);
        key->Translation(ignition::math::Vector3d(-4.5, -42.9, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.48));

        key = anim->CreateKeyFrame(25.4);
        key->Translation(ignition::math::Vector3d(-10.67, -3.49, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.48));

        key = anim->CreateKeyFrame(30.81);
        key->Translation(ignition::math::Vector3d(-16.7, 1.076, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));


		for (auto i = 39.615; i <= 159.615; i += 1.0)
		{
		    key = anim->CreateKeyFrame(39.615);
		    key->Translation(ignition::math::Vector3d(-5.71, 0.475, 0));
		    key->Rotation(ignition::math::Quaterniond(0, 0, 0.013));
		}



        key = anim->CreateKeyFrame(161.398);
        key->Translation(ignition::math::Vector3d(-8, -0.52, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.202));

        key = anim->CreateKeyFrame(167);
        key->Translation(ignition::math::Vector3d(-13.235, -6.374, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.6));

        key = anim->CreateKeyFrame(179.627);
        key->Translation(ignition::math::Vector3d(-11.85, -41.68, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.6));

        key = anim->CreateKeyFrame(183.491);
        key->Translation(ignition::math::Vector3d(-3.33, -48.35, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        key = anim->CreateKeyFrame(190.84);
        key->Translation(ignition::math::Vector3d(21, -48.35, 0));
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
  GZ_REGISTER_MODEL_PLUGIN(AnimatedFoodTruck)
}
