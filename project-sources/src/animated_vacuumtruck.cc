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
<<<<<<< HEAD
              new gazebo::common::PoseAnimation("animated_vacuumtruck", 302.651, true));
=======
              new gazebo::common::PoseAnimation("animated_vacuumtruck", 358.3765, true));
>>>>>>> 250fe32be137f608bb86cbbdb2adeaf61cc1f467

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
<<<<<<< HEAD
        key->Translation(ignition::math::Vector3d(-43, 69.8, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2.428));

        key = anim->CreateKeyFrame(18.689);
        key->Translation(ignition::math::Vector3d(-10, 39.42, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2.428));

        // set waypoint location
        key = anim->CreateKeyFrame(21.469);
        key->Translation(ignition::math::Vector3d(-4.168, 36.178, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, M_PI));;

        for (auto i=26.756; i < 276.756; i += 1.0) {
          // Animation de pose
          key = anim->CreateKeyFrame(i);
          key->Translation(ignition::math::Vector3d(-2.1657, 35.82, Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, M_PI));
        }

        key = anim->CreateKeyFrame(283);
        key->Translation(ignition::math::Vector3d(7.817, 40.798, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.59));

        key = anim->CreateKeyFrame(302.651);
        key->Translation(ignition::math::Vector3d(47.99, 65.36, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.59));


=======
        key->Translation(ignition::math::Vector3d(-42, 60, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.271));

        key = anim->CreateKeyFrame(13.9692);
        key->Translation(ignition::math::Vector3d(-10, 50, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.8505));

        // set waypoint location
        key = anim->CreateKeyFrame(16.3262);
        key->Translation(ignition::math::Vector3d(-6, 46, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.430));;

        /*key = anim->CreateKeyFrame(25.8277);
        key->Translation(ignition::math::Vector3d(-3, 35, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.558));;*/

        key = anim->CreateKeyFrame(28.1847);
        key->Translation(ignition::math::Vector3d(-5, 33, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        for (auto i=37.5139; i < 287.5139; i += 1.0) {
          // Animation de pose
          key = anim->CreateKeyFrame(i);
          key->Translation(ignition::math::Vector3d(-5, 28, Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));
        }

        key = anim->CreateKeyFrame(296.5181);
        key->Translation(ignition::math::Vector3d(-5, 33, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        /*key = anim->CreateKeyFrame(298.8765);
        key->Translation(ignition::math::Vector3d(-3, 35, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.558));*/

        key = anim->CreateKeyFrame(308.3765);
        key->Translation(ignition::math::Vector3d(-6, 46, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.430));

        key = anim->CreateKeyFrame(320.8765);
        key->Translation(ignition::math::Vector3d(-10, 50, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, M_PI/2));

        key = anim->CreateKeyFrame(358.3765);
        key->Translation(ignition::math::Vector3d(72, 50, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, M_PI/2));
>>>>>>> 250fe32be137f608bb86cbbdb2adeaf61cc1f467

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
