#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math.hh>
#include <stdio.h>

namespace gazebo
{
  class AnimatedBus : public ModelPlugin {
    public:
      //Set the animation for the vehicule model
      void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/) {

        std::cout << "Setting model..." << '\n';
        _model = _parent;

        std::cout << "Creating animation" << '\n';
        //Create the animation
        gazebo::common::PoseAnimationPtr anim(
          //Name the animation "Vehicule"
          //Make it last 10 seconds
          //Is set not to be a repeat loop
          new gazebo::common::PoseAnimation("Vehicule", 197.345, false));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of car
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(11, -3, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));
        std::cout << "Node 1 set" << '\n';
        
        arret = 10;
        depart = 160;

        for(auto i = arret; i <= depart; i+=10)
        {
          key = anim->CreateKeyFrame(i);
          key->Translation(ignition::math::Vector3d(9.66879, -4.90602, 0)); 
          key->Rotation(ignition::math::Quaterniond(0, -0, 0));
        }
        

        key = anim->CreateKeyFrame(170);
        key->Translation(ignition::math::Vector3d(5.25, -7.6795, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(176.1);
        key->Translation(ignition::math::Vector3d(5.25, -15, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(177.728);
        key->Translation(ignition::math::Vector3d(8, -18, 0.75));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.75));

        key = anim->CreateKeyFrame(184.5165);
        key->Translation(ignition::math::Vector3d(20, -30, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.75));

        key = anim->CreateKeyFrame(187.345);
        key->Translation(ignition::math::Vector3d(25, -35, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

        key = anim->CreateKeyFrame(197.345);
        key->Translation(ignition::math::Vector3d(50, -35, 0));
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

          std::cout << "Unloading the SUV" << '\n';
          sdf::SDF sphereSDF;
          std::stringstream sphereDesc;
          sphereDesc <<
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
          sphereSDF.SetFromString(sphereDesc.str());
          // Demonstrate using a custom model name.
          sdf::ElementPtr model = sphereSDF.Root()->GetElement("model");
          model->GetAttribute("name")->SetFromString("unique_sphere");
          _world->InsertModelSDF(sphereSDF);
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
