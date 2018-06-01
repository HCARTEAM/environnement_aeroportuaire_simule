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
  class AnimatedChassis : public ModelPlugin
  {
    public:
    void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/) {

        this->_model = _parent;

        number_fuelHandler = 1;
        hasAnimation = false;
        this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedChassis::OnUpdate, this, _1));

        
      }
    public:
      void OnUpdate(const common::UpdateInfo & /*_info*/) {

        if (!hasAnimation)
        {
          hasAnimation = true;
          double Zpos(_model->GetWorldPose().pos.z);
          std::vector<double> x;
          std::vector<double> y;

          for (int i = 0; i < 16; ++i)
          {
 		if (i > 1 && i < 4)
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
                new gazebo::common::PoseAnimation("animated_chassis", 600, false));

          gazebo::common::PoseKeyFrame *key;

          // set starting location of the box
          key = anim->CreateKeyFrame(0);
          key->Translation(ignition::math::Vector3d(-27 + x[0], 46 + y[0], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 2.23));

          key = anim->CreateKeyFrame(10);
          key->Translation(ignition::math::Vector3d(-11 + x[1], 23 + y[1], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 2.23));

          key = anim->CreateKeyFrame(12.58);
          key->Translation(ignition::math::Vector3d(-9 + x[2], 20 + y[2], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

          arret = 17.58;
          depart = 217.58;
          for (auto i = arret; i <= depart; i += 1)
          {
            key = anim->CreateKeyFrame(i);
            key->Translation(ignition::math::Vector3d(-9, 13, Zpos));
            key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));
          }
	
	  key = anim->CreateKeyFrame(219.9);
          key->Translation(ignition::math::Vector3d(-9+ x[3], 15 + y[3], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));


          key = anim->CreateKeyFrame(221.9);
          key->Translation(ignition::math::Vector3d(-13 + x[4], 13 + y[4], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));

          key = anim->CreateKeyFrame(232.6);
          key->Translation(ignition::math::Vector3d(-28 + x[5], 13 + y[5], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));

          key = anim->CreateKeyFrame(238.17);
          key->Translation(ignition::math::Vector3d(-33 + x[6], 16.5 + y[6], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, -1.57));

          key = anim->CreateKeyFrame(251.9);
          key->Translation(ignition::math::Vector3d(-33 + x[7], 53 + y[7], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, -1.57));

          key = anim->CreateKeyFrame(255.2);
          key->Translation(ignition::math::Vector3d(-26 + x[8], 59 + y[8], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

          key = anim->CreateKeyFrame(267.5);
          key->Translation(ignition::math::Vector3d(8.5 + x[9], 59 + y[9], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

          key = anim->CreateKeyFrame(273.18);
          key->Translation(ignition::math::Vector3d(15 + x[10], 54.5 + y[10], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 1.39));

          key = anim->CreateKeyFrame(292.3);
          key->Translation(ignition::math::Vector3d(11 + x[11], 28 + y[11], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 1.39));

          key = anim->CreateKeyFrame(297.33);
          key->Translation(ignition::math::Vector3d(11 + x[12], 21 + y[12], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

          for (auto i = 303; i <= 503; i += 5)
          {
            key = anim->CreateKeyFrame(i);
            key->Translation(ignition::math::Vector3d(11, 13, Zpos));
            key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));
          }

          key = anim->CreateKeyFrame(508.4);
          key->Translation(ignition::math::Vector3d(15.5 + x[13], 7 + y[13], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

          key = anim->CreateKeyFrame(514.5);
          key->Translation(ignition::math::Vector3d(24 + x[14], 7 + y[14], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

          key = anim->CreateKeyFrame(520);
          key->Translation(ignition::math::Vector3d(30 + x[15], 12 + y[15], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, -1.92));

          end_anim = 532.8;
          key = anim->CreateKeyFrame(end_anim);
          key->Translation(ignition::math::Vector3d(41 + x[16], 46 + y[16], Zpos));
          key->Rotation(ignition::math::Quaterniond(0, 0, -1.92));

          // set the animation to the model
          _model->SetAnimation(anim);
          _anim = anim;
          _world = _model->GetWorld();

          this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
            boost::bind(&AnimatedChassis::OnUpdate, this, _1));

        }
        else
        {
          temps = _anim->GetTime();
          if (number_fuelHandler > 0 && temps > arret && temps < depart) {
            const math::Pose &modelPose = _model->GetWorldPose();

            sdf::SDF fuelHandlerSDF;
            std::stringstream fuelHandlerDesc;
            fuelHandlerDesc <<
        "<sdf version ='1.4'>\
                           <model name ='fuelHandler'>\
                             <pose> 4.07524 0.063808 0.112085 1e-06 -1e-06 1.513</pose>\
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
                             <plugin name='animated_fuelhandlerc' filename='libanimated_fuelhandlerc.so'/>\
                           </model>\
                         </sdf>";
            fuelHandlerSDF.SetFromString(fuelHandlerDesc.str());
            // Demonstrate using a custom model name.
            sdf::ElementPtr model = fuelHandlerSDF.Root()->GetElement("model");
            model->GetAttribute("name")->SetFromString("fuelHandler");
            _world->InsertModelSDF(fuelHandlerSDF);
            number_fuelHandler--;
          }
          else if (temps > end_anim)
          {
            _model->StopAnimation();
            number_fuelHandler = 1;
            hasAnimation = false;
          }
        }
      }

    // Pointer to the model
    private: physics::ModelPtr _model;
    physics::WorldPtr _world;
    gazebo::common::PoseAnimationPtr _anim;

    private:
    double temps, arret, depart, end_anim;
    bool hasAnimation = false;
    int number_fuelHandler;

    // Pointer to the update event connection
    private: event::ConnectionPtr _updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedChassis)
}
