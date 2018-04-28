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
  class AnimatedFuelTruck : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->model = _parent;

      double Zpos(model->GetWorldPose().pos.z);

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 200 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("animated_fueltruck", 573.5, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(-44, 62.7, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2));

        key = anim->CreateKeyFrame(13.26);
        key->Translation(ignition::math::Vector3d(-25.5, 30.5, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2));

        key = anim->CreateKeyFrame(23.67);
        key->Translation(ignition::math::Vector3d(-20, 17, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

		for (auto i = 27.96; i <= 228; i += 1)
		{
			key = anim->CreateKeyFrame(i);
			key->Translation(ignition::math::Vector3d(-20, 11, Zpos));
			key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));
		}

        key = anim->CreateKeyFrame(235);
        key->Translation(ignition::math::Vector3d(-26, 3.3, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(246.3);
        key->Translation(ignition::math::Vector3d(-42, 3.3, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(257.8);
        key->Translation(ignition::math::Vector3d(-53,15, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(272);
        key->Translation(ignition::math::Vector3d(-53, 55, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(278.1);
        key->Translation(ignition::math::Vector3d(-37, 60, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(302);
        key->Translation(ignition::math::Vector3d(30, 60, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(309.9);
        key->Translation(ignition::math::Vector3d(30, 49, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.22));

        key = anim->CreateKeyFrame(326.8);
        key->Translation(ignition::math::Vector3d(20, 27.5, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.22));

        key = anim->CreateKeyFrame(332.9);
        key->Translation(ignition::math::Vector3d(19, 19, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(338.65);
        key->Translation(ignition::math::Vector3d(19, 11, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(538.65);
        key->Translation(ignition::math::Vector3d(19, 11, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(545.7);
        key->Translation(ignition::math::Vector3d(26, 4, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(555.7);
        key->Translation(ignition::math::Vector3d(40, 4, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(562);
        key->Translation(ignition::math::Vector3d(42, 13, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.2));

        key = anim->CreateKeyFrame(573.5);
        key->Translation(ignition::math::Vector3d(51, 43, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.2));

        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedFuelTruck)
}
