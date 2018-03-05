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
  class AnimatedFuelTank : public ModelPlugin
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
              new gazebo::common::PoseAnimation("fueltank_animation", 530, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(-46, 36.3, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.28));

        key = anim->CreateKeyFrame(10.43);
        key->Translation(ignition::math::Vector3d(-21.8, 25.7, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.28));

        key = anim->CreateKeyFrame(18.46);
        key->Translation(ignition::math::Vector3d(-14.68, 17, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(20.81);
        key->Translation(ignition::math::Vector3d(-14.68, 13.7, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(220.81);
        key->Translation(ignition::math::Vector3d(-14.68, 13.7, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(228.84);
        key->Translation(ignition::math::Vector3d(-23.6, 6.86, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.57));

        key = anim->CreateKeyFrame(233.4);
        key->Translation(ignition::math::Vector3d(-27, 6.86, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.57));

        key = anim->CreateKeyFrame(240.35);
        key->Translation(ignition::math::Vector3d(-33, 14.5, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, -3.14));

        key = anim->CreateKeyFrame(249.39);
        key->Translation(ignition::math::Vector3d(-33, 39.8, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, -3.14));

        key = anim->CreateKeyFrame(255.28);
        key->Translation(ignition::math::Vector3d(-23.1, 53, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(263.9);
        key->Translation(ignition::math::Vector3d(1.11, 53, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(273.1);
        key->Translation(ignition::math::Vector3d(9.98, 43.7, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, -0.15));

        key = anim->CreateKeyFrame(285.9);
        key->Translation(ignition::math::Vector3d(5.3, 26.4, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.15));

        key = anim->CreateKeyFrame(295.0);
        key->Translation(ignition::math::Vector3d(4.2, 13.7, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(495.0);
        key->Translation(ignition::math::Vector3d(4.2, 13.7, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(501.9);
        key->Translation(ignition::math::Vector3d(11.74, 7.62, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(506.4);
        key->Translation(ignition::math::Vector3d(18, 7.62, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(511.56);
        key->Translation(ignition::math::Vector3d(24.53, 10.7, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2.24));

        key = anim->CreateKeyFrame(524.76);
        key->Translation(ignition::math::Vector3d(51.19, 36.3, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2.24));

        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedFuelTank)
}
