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

namespace gazebo
{
  class AnimatedPassenger : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->_model = _parent;
      const math::Pose& modelPose = _model->GetWorldPose();

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 10 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("test", 10.0, false));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(modelPose.pos.Ign());
        key->Rotation(modelPose.rot.Ign());

        // set final location equal to starting location
        key = anim->CreateKeyFrame(10);
        key->Translation(ignition::math::Vector3d(7.23907, -8.00261, 0));
        key->Rotation(ignition::math::Quaterniond(0, -0, 0));

        // set the animation
        _parent->SetAnimation(anim);
        _anim = anim;

        this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedPassenger::OnUpdate, this, _1));
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
  GZ_REGISTER_MODEL_PLUGIN(AnimatedPassenger)
}
