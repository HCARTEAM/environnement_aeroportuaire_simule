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
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->_model = _parent;

      double Zpos(_model->GetWorldPose().pos.z);

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 200 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("animated_train", 353.679, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(45.47, -43.677, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        // set waypoint location
        key = anim->CreateKeyFrame(15.308);
        key->Translation(ignition::math::Vector3d(7.2, -43.43, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        key = anim->CreateKeyFrame(23.866);
        key->Translation(ignition::math::Vector3d(-13.37, -37.55, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.794));

        key = anim->CreateKeyFrame(34.7);
        key->Translation(ignition::math::Vector3d(-19.39, -11.135, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.794));

        key = anim->CreateKeyFrame(42.812);
        key->Translation(ignition::math::Vector3d(-22.17, 2, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        key = anim->CreateKeyFrame(45.66);
        key->Translation(ignition::math::Vector3d(-25.66, 1.5, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        key = anim->CreateKeyFrame(54.66);
        key->Translation(ignition::math::Vector3d(-8.3, 4.2, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));


      	for (auto i = 63; i <= 303; i++)
      	{
      		key = anim->CreateKeyFrame(i);
      	    key->Translation(ignition::math::Vector3d(-5.983, 5.146, Zpos));
      	    key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));
      	}


        key = anim->CreateKeyFrame(309);
        key->Translation(ignition::math::Vector3d(-12.68, 1.837, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 2.87));

        key = anim->CreateKeyFrame(320);
        key->Translation(ignition::math::Vector3d(-18.46, -9.06, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.41));

        key = anim->CreateKeyFrame(327.86);
        key->Translation(ignition::math::Vector3d(-14.2, -28.18, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.41));

        key = anim->CreateKeyFrame(338.37);
        key->Translation(ignition::math::Vector3d(7.2, -43.43, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(353.679);
        key->Translation(ignition::math::Vector3d(45.47, -43.677, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0 ));

        number_baggageHandler = 1;
        // set the animation
        _parent->SetAnimation(anim);
        _anim = anim;
        _world = _model->GetWorld();

        this->updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedTrain::OnUpdate, this, _1));
    }

  public:
    void OnUpdate(const common::UpdateInfo & /*_info*/) {
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
      }


    // Pointer to the model
    private:
      physics::ModelPtr _model;
      physics::WorldPtr _world;
      gazebo::common::PoseAnimationPtr _anim;
      int number_baggageHandler = 1;



    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedTrain)
}
