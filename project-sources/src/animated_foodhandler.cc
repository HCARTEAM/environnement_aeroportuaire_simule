/*
 * Copyright (C) 2012-2015 Open Source Robotics Foundation
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
#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <ignition/math.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <gazebo/math/gzmath.hh>
#include <stdio.h>
#include <sae_globals.hh>

namespace gazebo
{
  class AnimatedFoodHandler : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {

      this->_model = _parent;

      double Zpos(_model->GetWorldPose().pos.z);

      const math::Pose& modelPose = _model->GetWorldPose();

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              new gazebo::common::PoseAnimation("foodhandler", 111.36, false));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the baggage handler
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(-7.35, -1.77, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        // set final location of the baggage handler
        key = anim->CreateKeyFrame(1);
        key->Translation(ignition::math::Vector3d(-7.35, -1.77, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI) / 2));

        for (double d = 6.01; d <= 36.01; d+= 1.0)
        {
          key = anim->CreateKeyFrame(d);
          key->Translation(ignition::math::Vector3d(-2.34, -1.77, 0.082));
          key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI) / 2));
        }
        key = anim->CreateKeyFrame(37.01);
        key->Translation(ignition::math::Vector3d(-2.34, -1.77, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI) / 2));

        key = anim->CreateKeyFrame(44.67);
        key->Translation(ignition::math::Vector3d(-10.0, -1.77, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI) / 2));

        key = anim->CreateKeyFrame(45.17);
        key->Translation(ignition::math::Vector3d(-10.0, -1.77, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.16));

        key = anim->CreateKeyFrame(52.89);
        key->Translation(ignition::math::Vector3d(-15.02, 4.1, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI)));

        key = anim->CreateKeyFrame(56.64);
        key->Translation(ignition::math::Vector3d(-15.02, 7.85, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2.58));
        
        for (double d = 60.94 ; d <= 90.94; d+= 1.0)
        {
          key = anim->CreateKeyFrame(d);
          key->Translation(ignition::math::Vector3d(-10.74, 8.25, 0.082));
          key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI)/2));
        }

        key = anim->CreateKeyFrame(91.94);
        key->Translation(ignition::math::Vector3d(-10.74, 8.25, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI)/2));

        key = anim->CreateKeyFrame(96.24);
        key->Translation(ignition::math::Vector3d(-15.02, 7.85, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -0.56));

        key = anim->CreateKeyFrame(99.99);
        key->Translation(ignition::math::Vector3d(-15.02, 4.1, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(107.71);
        key->Translation(ignition::math::Vector3d(-10.0, -2, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.98));


        key = anim->CreateKeyFrame(110.36);
        key->Translation(ignition::math::Vector3d(-7.35, -2, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI)/2));

        key = anim->CreateKeyFrame(111.36);
        key->Translation(ignition::math::Vector3d(-7.35, -2, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI)));

        // set the animation
        _parent->SetAnimation(anim);
        _anim = anim;

        this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedFoodHandler::OnUpdate, this, _1));
    }

    public: void OnUpdate(const common::UpdateInfo & /*_info*/) {
      if (_anim->GetTime() >= _anim->GetLength()) {
          _model->GetWorld()->RemoveModel(_model);
      }

    }

  private: gazebo::common::PoseAnimationPtr _anim;

    // Pointer to the model
    private: physics::ModelPtr _model;

    // Pointer to the update event connection
    private: event::ConnectionPtr _updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedFoodHandler)
}
