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
  class AnimatedVacuumTruck : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->model = _parent;

      double Zpos(model->GetWorldPose().pos.z);

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              new gazebo::common::PoseAnimation("animated_vacuumtruck", 368.5425, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(-42, 60, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.271));

        // set waypoint location
        key = anim->CreateKeyFrame(16.0943);
        key->Translation(ignition::math::Vector3d(-6, 46, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.430));;

        /*key = anim->CreateKeyFrame(25.5958);
        key->Translation(ignition::math::Vector3d(-3, 35, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.558));;*/

        key = anim->CreateKeyFrame(27.9528);
        key->Translation(ignition::math::Vector3d(-5, 33, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        for (auto i=38.9136; i < 288.9136; i += 1.0){
          // Animation de pose
          key = anim->CreateKeyFrame(i);
          key->Translation(ignition::math::Vector3d(-5, 22, Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));
        }

        key = anim->CreateKeyFrame(298.0802);
        key->Translation(ignition::math::Vector3d(-5, 33, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        /*key = anim->CreateKeyFrame(309.0410);
        key->Translation(ignition::math::Vector3d(-3, 35, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.558));*/

        key = anim->CreateKeyFrame(318.5425);
        key->Translation(ignition::math::Vector3d(-6, 46, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.430));

        key = anim->CreateKeyFrame(331.0425);
        key->Translation(ignition::math::Vector3d(-18, 55, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, M_PI/2));

        key = anim->CreateKeyFrame(368.5425);
        key->Translation(ignition::math::Vector3d(72, 55, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, M_PI/2));

        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedVacuumTruck)
}
