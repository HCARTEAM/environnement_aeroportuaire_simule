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
  class AnimatedFoodTruck : public ModelPlugin
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
              new gazebo::common::PoseAnimation("animated_foodtruck", 190.84, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(21, -48.35, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        // set waypoint location
        key = anim->CreateKeyFrame(8.167);
        key->Translation(ignition::math::Vector3d(1.87, -48.35, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(11.16);
        key->Translation(ignition::math::Vector3d(-4.5, -42.9, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.48));

        key = anim->CreateKeyFrame(25.4);
        key->Translation(ignition::math::Vector3d(-10.67, -3.49, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.48));

        key = anim->CreateKeyFrame(30.81);
        key->Translation(ignition::math::Vector3d(-16.7, 1.076, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(35.81);
        key->Translation(ignition::math::Vector3d(-10.7, 0.776, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

    		for (auto i = 39.615; i <= 159.615; i += 1.0)
    		{
    		    key = anim->CreateKeyFrame(i);
    		    key->Translation(ignition::math::Vector3d(-5.71, 0.475, Zpos));
    		    key->Rotation(ignition::math::Quaterniond(0, 0, 0.013));
    		}

        key = anim->CreateKeyFrame(161.398);
        key->Translation(ignition::math::Vector3d(-8, -0.52, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.202));

        key = anim->CreateKeyFrame(167);
        key->Translation(ignition::math::Vector3d(-13.235, -6.374, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.6));

        key = anim->CreateKeyFrame(179.627);
        key->Translation(ignition::math::Vector3d(-11.85, -41.68, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.6));

        key = anim->CreateKeyFrame(183.491);
        key->Translation(ignition::math::Vector3d(-3.33, -48.35, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

        key = anim->CreateKeyFrame(190.84);
        key->Translation(ignition::math::Vector3d(21, -48.35, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));


        number_foodHandler = 1;

        // set the animation
        _parent->SetAnimation(anim);
        _anim = anim;
        _world = _model->GetWorld();

        this->updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&AnimatedFoodTruck::OnUpdate, this, _1));
    }

  public:
    void OnUpdate(const common::UpdateInfo & /*_info*/) {
        double temps = _anim->GetTime();

        if (number_foodHandler > 0 && temps > 40 && temps < 160) {
          const math::Pose &modelPose = _model->GetWorldPose();

          sdf::SDF foodHandlerSDF;
          std::stringstream foodHandlerDesc;
          foodHandlerDesc <<
          "<sdf version ='1.4'>\
             <model name ='foodhandler'>\
               <pose> -7.35 -1.77 0.082 0.0 0 0</pose>\
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
               <plugin name='animated_foodhandler' filename='libanimated_foodhandler.so'/>\
             </model>\
           </sdf>";
          foodHandlerSDF.SetFromString(foodHandlerDesc.str());
          // Demonstrate using a custom model name.
          sdf::ElementPtr model = foodHandlerSDF.Root()->GetElement("model");
          model->GetAttribute("name")->SetFromString("foodhandler");
          _world->InsertModelSDF(foodHandlerSDF);
          number_foodHandler--;
        }
      }


    // Pointer to the model
    private:
      physics::ModelPtr _model;
      physics::WorldPtr _world;
      gazebo::common::PoseAnimationPtr _anim;
      int number_foodHandler = 1;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedFoodTruck)
}
