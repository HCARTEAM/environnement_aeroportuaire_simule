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
  class AnimatedPassenger : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {

      this->_model = _parent;

      double Zpos(_model->GetWorldPose().pos.z);
      

      const math::Pose& modelPose = _model->GetWorldPose();

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              new gazebo::common::PoseAnimation("passenger", 10.0, false));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the passenger
        key = anim->CreateKeyFrame(0);
        key->Translation(modelPose.pos.Ign());
        key->Rotation(modelPose.rot.Ign());

        double x = math::Rand::GetDblUniform(-0.5, 0.5);
        double y = math::Rand::GetDblUniform(-0.5, 0.5);
        // set final location of the passenger
        key = anim->CreateKeyFrame(10);
        key->Translation(ignition::math::Vector3d(7.23907 + x, -8.00261 + y, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, -0, 0));

        // set the animation
        _parent->SetAnimation(anim);
        _anim = anim;

        this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedPassenger::OnUpdate, this, _1));
    }

    public: void OnUpdate(const common::UpdateInfo & /*_info*/) {
    
      /* Destroy the passenger when they arrive */
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
  GZ_REGISTER_MODEL_PLUGIN(AnimatedPassenger)
}
