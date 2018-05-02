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
              new gazebo::common::PoseAnimation("animated_vacuumtruck", 398.8851, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(-42, 60, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -0.92));

        // set waypoint location
        key = anim->CreateKeyFrame(3.4409);
        key->Translation(ignition::math::Vector3d(-35, 55, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -0.62));

        key = anim->CreateKeyFrame(24);
        key->Translation(ignition::math::Vector3d(-13, 44, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -0.45));

        //key = anim->CreateKeyFrame(26.3324);
        //key->Translation(ignition::math::Vector3d(-8, 41, Zpos));
        //key->Rotation(ignition::math::Quaterniond(0, 0, -0.20));

        key = anim->CreateKeyFrame(34.1192);
        key->Translation(ignition::math::Vector3d(-5, 20, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -M_PI/2));

        for (auto i=44.1192; i < 294.1192; i += 10.0){
          // Animation de pose
          key = anim->CreateKeyFrame(i);
          key->Translation(ignition::math::Vector3d(-5, 32, Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, -M_PI/2));
        }

        key = anim->CreateKeyFrame(304.1192);
        key->Translation(ignition::math::Vector3d(-5, 20, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -M_PI/2));

        key = anim->CreateKeyFrame(327.6895);
        key->Translation(ignition::math::Vector3d(-25, 40, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(359.3671);
        key->Translation(ignition::math::Vector3d(13, 41, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.25));

        key = anim->CreateKeyFrame(387.2184);
        key->Translation(ignition::math::Vector3d(39, 62, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.30));

        key = anim->CreateKeyFrame(398.8851);
        key->Translation(ignition::math::Vector3d(53, 62, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.30));

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
