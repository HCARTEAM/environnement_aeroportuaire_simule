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
#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math.hh>
#include <stdio.h>
#include <sae_globals.hh>

namespace gazebo
{
  class AnimatedBus : public ModelPlugin {
    public:

      void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/) {

        _model = _parent;

        //Create the animation of the bus
        gazebo::common::PoseAnimationPtr anim(
          new gazebo::common::PoseAnimation("Bus", 197.345, false));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the bus
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(11, -3, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        arret = 10;
        depart = 160;

        for(auto i = arret; i <= depart; i+=10)
        {
          key = anim->CreateKeyFrame(i);
          key->Translation(ignition::math::Vector3d(9.66879, -4.90602, Ground_ZPos));
          key->Rotation(ignition::math::Quaterniond(0, -0, 0));
        }

        key = anim->CreateKeyFrame(170);
        key->Translation(ignition::math::Vector3d(5.25, -7.6795, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(176.1);
        key->Translation(ignition::math::Vector3d(5.25, -15, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(177.728);
        key->Translation(ignition::math::Vector3d(8, -18, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.75));

        key = anim->CreateKeyFrame(184.5165);
        key->Translation(ignition::math::Vector3d(20, -30, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.75));

        key = anim->CreateKeyFrame(187.345);
        key->Translation(ignition::math::Vector3d(25, -35, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(197.345);
        key->Translation(ignition::math::Vector3d(50, -35, Ground_ZPos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        // set the animation to the model
        std::cout << "Set the animation" << '\n';
        _model->SetAnimation(anim);
        _anim = anim;
        _world = _model->GetWorld();
	intervalle = (depart - arret) / double(number_passenger);

        this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedBus::OnUpdate, this, _1));
      }

    public:
      void OnUpdate(const common::UpdateInfo & /*_info*/) {
        double temps = _anim->GetTime();

        if (loaded && temps > arret && temps < depart) {
          const math::Pose &modelPose = _model->GetWorldPose();

          sdf::SDF passengerSDF;
          std::stringstream passengerDesc;
          passengerDesc <<
			"<sdf version ='1.4'>\
                         <model name ='passenger'>\
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
                           <plugin name='animated_passenger' filename='libanimated_passenger.so'/>\
                         </model>\
                       </sdf>";
								/* <mesh>\
				 					<scale>1 1 1</scale>\
                                 <uri>model://person_walking/meshes/walking.dae</uri>\
								</mesh>\ */
          passengerSDF.SetFromString(passengerDesc.str());
          // Demonstrate using a custom model name.
          sdf::ElementPtr model = passengerSDF.Root()->GetElement("model");
          model->GetAttribute("name")->SetFromString("unique_passenger");
          _world->InsertModelSDF(passengerSDF);
	  //_world->InsertModelFile("model://passenger");
          number_passenger--;
	  arret += intervalle;
          loaded = number_passenger != 0;

        }

      }

    private:
      physics::ModelPtr _model;
      physics::WorldPtr _world;
      gazebo::common::PoseAnimationPtr _anim;
      event::ConnectionPtr _updateConnection;
      int number_passenger = 20;
      double arret, depart, intervalle;
      bool loaded = true, arrete = true;
  };
  GZ_REGISTER_MODEL_PLUGIN(AnimatedBus);
}
