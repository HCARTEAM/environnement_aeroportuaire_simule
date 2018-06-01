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
  class AnimatedBaggageHandler : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {

      this->_model = _parent;

      double Zpos(_model->GetWorldPose().pos.z);


      const math::Pose& modelPose = _model->GetWorldPose();

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              new gazebo::common::PoseAnimation("baggagehandler", 232.0, false));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the baggage handler
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(-11.53, 2.8, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI) / 2));

        // set final location of the baggage handler
        key = anim->CreateKeyFrame(9);
        key->Translation(ignition::math::Vector3d(-3.0, 2.8, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI) / 2));

        key = anim->CreateKeyFrame(10);
        key->Translation(ignition::math::Vector3d(-3.5, 2.8, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI) / 2));

        key = anim->CreateKeyFrame(20.53);
        key->Translation(ignition::math::Vector3d(-14.0, 2.8, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI) / 2));

        key = anim->CreateKeyFrame(21.53);
        key->Translation(ignition::math::Vector3d(-14.0, 3.2, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI)));

        key = anim->CreateKeyFrame(24.15);
        key->Translation(ignition::math::Vector3d(-14.0, 7.25, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI)));

        key = anim->CreateKeyFrame(27.15);
        key->Translation(ignition::math::Vector3d(-9.63, 7.25, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI)/2));

        for (double d = 28.6; d <= 173.6; d+= 1.0)
        {
          key = anim->CreateKeyFrame(d);
          key->Translation(ignition::math::Vector3d(-9.63, 8.14, 0.082));
          key->Rotation(ignition::math::Quaterniond(0, 0, -M_PI));
        }
        
        key = anim->CreateKeyFrame(178.07);
        key->Translation(ignition::math::Vector3d(-14.0, 7.25, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(180.69);
        key->Translation(ignition::math::Vector3d(-14.0, 3.2, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(181.69);
        key->Translation(ignition::math::Vector3d(-14.0, 2.8, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI) / 2));

        key = anim->CreateKeyFrame(192.2);
        key->Translation(ignition::math::Vector3d(-3.0, 2.8, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, (M_PI) / 2));

        key = anim->CreateKeyFrame(193.2);
        key->Translation(ignition::math::Vector3d(-3.5, 2.8, 0.082));
        key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI) / 2));

        for (double d = 202; d <= 232; d+= 5)
        {
          key = anim->CreateKeyFrame(d);
          key->Translation(ignition::math::Vector3d(-11.53, 2.8, 0.082));
          key->Rotation(ignition::math::Quaterniond(0, 0, -(M_PI) / 2));

        }


        // set the animation
        _parent->SetAnimation(anim);
        _anim = anim;

        this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedBaggageHandler::OnUpdate, this, _1));
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
  GZ_REGISTER_MODEL_PLUGIN(AnimatedBaggageHandler)
}
