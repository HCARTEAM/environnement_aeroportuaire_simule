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
  class AnimatedTrain : public ModelPlugin
  {

    public: 
    void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/) {

        this->_model = _parent;

        number_baggageHandler = 1;
        hasAnimation = false;
        this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedTrain::OnUpdate, this, _1));

      }

    public:
    void OnUpdate(const common::UpdateInfo & /*_info*/) {
      if (!hasAnimation)
      {
        hasAnimation = true;
        double Zpos(_model->GetWorldPose().pos.z);
        std::vector<double> x;
        std::vector<double> y;

        for (int i = 0; i < 12; ++i)
        {
          if (i > 4 && i < 9)
          {
            x.push_back(math::Rand::GetDblUniform(-0.5, 0.5));
            y.push_back(math::Rand::GetDblUniform(-0.5, 0.5));
          }
          else
          {
            x.push_back(math::Rand::GetDblUniform(-1.0, 1.0));
            y.push_back(math::Rand::GetDblUniform(-1.0, 1.0));
          }
        }

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 200 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("animated_train", 400.0, false));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(45.47 + x[0], -43.677 + y[0], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        // set waypoint location
        key = anim->CreateKeyFrame(15.308);
        key->Translation(ignition::math::Vector3d(7.2 + x[1], -43.43 + y[1], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        key = anim->CreateKeyFrame(23.866);
        key->Translation(ignition::math::Vector3d(-13.37 + x[2], -37.55 + y[2], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.794));

        key = anim->CreateKeyFrame(34.7);
        key->Translation(ignition::math::Vector3d(-19.39 + x[3], -11.135 + y[3], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.794));

        key = anim->CreateKeyFrame(42.812);
        key->Translation(ignition::math::Vector3d(-22.17 + x[4], 2 + y[4], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        key = anim->CreateKeyFrame(45.66);
        key->Translation(ignition::math::Vector3d(-25.66 + x[5], 1.5 + y[5], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        key = anim->CreateKeyFrame(54.66);
        key->Translation(ignition::math::Vector3d(-8.3 + x[6], 4.2 + y[6], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));


        for (auto i = 63; i <= 303; i++)
        {
          key = anim->CreateKeyFrame(i);
            key->Translation(ignition::math::Vector3d(-5.983, 5.146, Zpos));
            key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));
        }


        key = anim->CreateKeyFrame(309);
        key->Translation(ignition::math::Vector3d(-12.68 + x[7], 1.837 + y[7], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.87));

        key = anim->CreateKeyFrame(320);
        key->Translation(ignition::math::Vector3d(-18.46 + x[8], -9.06 + y[8], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.41));

        key = anim->CreateKeyFrame(327.86);
        key->Translation(ignition::math::Vector3d(-14.2 + x[9], -28.18 + y[9], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.41));

        key = anim->CreateKeyFrame(338.37);
        key->Translation(ignition::math::Vector3d(7.2 + x[10], -43.43 + y[10], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(353.679);
        key->Translation(ignition::math::Vector3d(45.47 + x[11], -43.677 + y[11], Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0 ));

        number_baggageHandler = 1;
        // set the animation
        _model->SetAnimation(anim);
        _anim = anim;
        _world = _model->GetWorld();

        this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedTrain::OnUpdate, this, _1));
      }
      else
      {
        double temps = _anim->GetTime();

        if (number_baggageHandler > 0 && temps > 63 && temps < 303) {
          const math::Pose &modelPose = _model->GetWorldPose();

          sdf::SDF baggageHandlerSDF;
          std::stringstream baggageHandlerDesc;
          baggageHandlerDesc <<
          "<sdf version ='1.4'>\
             <model name ='baggagehandler'>\
               <pose> -11.53 2.8 0.082 0.0 0 1.57</pose>\
               <link name ='link'>\
                 <pose>0 0 0.2 0 0 0</pose>\
                 <collision name ='collision'>\
                   <geometry>\
                    <mesh>\
                      <scale>1 1 1</scale>\
                        <uri>model://person_walking/meshes/walking.dae</uri>\
                    </mesh>\
                   </geometry>\
                 </collision>\
                 <visual name ='visual'>\
                   <geometry>\
                    <mesh>\
                      <scale>1 1 1</scale>\
                        <uri>model://person_walking/meshes/walking.dae</uri>\
                    </mesh>\
                   </geometry>\
                 </visual>\
               </link>\
               <plugin name='animated_baggagehandler' filename='libanimated_baggagehandler.so'/>\
             </model>\
           </sdf>";
          baggageHandlerSDF.SetFromString(baggageHandlerDesc.str());
          // Demonstrate using a custom model name.
          sdf::ElementPtr model = baggageHandlerSDF.Root()->GetElement("model");
          model->GetAttribute("name")->SetFromString("baggagehandler");
          _world->InsertModelSDF(baggageHandlerSDF);
          number_baggageHandler--;
        }
        else if(temps > 353.679)
        {
          _model->StopAnimation();
          number_baggageHandler = 1;
          hasAnimation = false;
        }
      }
    }


    // Pointer to the model
    private:
      physics::ModelPtr _model;
      physics::WorldPtr _world;
      gazebo::common::PoseAnimationPtr _anim;
      int number_baggageHandler = 1;
      bool hasAnimation = false;



    // Pointer to the update event connection
    private: event::ConnectionPtr _updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedTrain)
}
