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
#include <sae_globals.hh>

namespace gazebo
{
  class AnimatedChassis : public ModelPlugin
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
              new gazebo::common::PoseAnimation("animated_chassis", 532.8, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(-27, 46, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2.23));

        key = anim->CreateKeyFrame(10);
        key->Translation(ignition::math::Vector3d(-11, 23, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2.23));

        key = anim->CreateKeyFrame(12.58);
        key->Translation(ignition::math::Vector3d(-9, 20, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

		for (auto i = 17.58; i <= 217.58; i += 1)
		{
		    key = anim->CreateKeyFrame(i);
		    key->Translation(ignition::math::Vector3d(-9, 13, Ground_ZPos));
		    key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));
		}

        key = anim->CreateKeyFrame(221.9);
        key->Translation(ignition::math::Vector3d(-13, 8.5, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(232.6);
        key->Translation(ignition::math::Vector3d(-28, 8.5, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(238.17);
        key->Translation(ignition::math::Vector3d(-33, 14.5, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(251.9);
        key->Translation(ignition::math::Vector3d(-33, 53, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(255.2);
        key->Translation(ignition::math::Vector3d(-26, 59, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(267.5);
        key->Translation(ignition::math::Vector3d(8.5, 59, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(273.18);
        key->Translation(ignition::math::Vector3d(15, 54.5, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.39));

        key = anim->CreateKeyFrame(292.3);
        key->Translation(ignition::math::Vector3d(11, 28, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.39));

        key = anim->CreateKeyFrame(297.33);
        key->Translation(ignition::math::Vector3d(11, 21, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(303);
        key->Translation(ignition::math::Vector3d(11, 13, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(503);
        key->Translation(ignition::math::Vector3d(11, 13, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(508.4);
        key->Translation(ignition::math::Vector3d(15.5, 7, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(514.5);
        key->Translation(ignition::math::Vector3d(24, 7, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(520);
        key->Translation(ignition::math::Vector3d(30, 12, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.22));

        key = anim->CreateKeyFrame(532.8);
        key->Translation(ignition::math::Vector3d(41, 46, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.22));

        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedChassis)
}
