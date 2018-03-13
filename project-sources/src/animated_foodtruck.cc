#include <gazebo/gazebo.hh>
#include <ignition/math.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <vehicule.hh>
#include <stdio.h>

namespace gazebo
{
  class AnimatedFoodTruck : public ModelPlugin, Vehicule
  {
    public: void Load(physics::ModelPtr parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->_model = parent;

        std::list<std::pair<Spacestamp, Timestamp>> trajectory = {
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(46, -48, 0),
            ignition::math::Quaterniond(0, 0, 0)),
            Timestamp(MOVE,2.8)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-2.5, -48, 0),
            ignition::math::Quaterniond(0, 0, 0)),
            Timestamp(MOVE,2.8)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-6.5, -42.9, 0),
            ignition::math::Quaterniond(0, 0, -1.37)),
            Timestamp(MOVE,2.8)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-14.9, -1.67, 0),
            ignition::math::Quaterniond(0, 0, -1.37)),
            Timestamp(MOVE,2.8)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-19, 3.16, 0),
            ignition::math::Quaterniond(0, 0, 0)),
            Timestamp(MOVE,1.4)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-21, 3.16, 0),
            ignition::math::Quaterniond(0, 0, 0)),
            Timestamp(MOVE,1.4)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-19, 3.16, 0),
            ignition::math::Quaterniond(0, 0, 0)),
            Timestamp(MOVE,1.4)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-9, 3.16, 0),
            ignition::math::Quaterniond(0, 0, 0)),
            Timestamp(WAIT,120)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-9, 3.16, 0),
            ignition::math::Quaterniond(0, 0, 0)),
            Timestamp(MOVE,1.4)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-12.8, 3.16, 0),
            ignition::math::Quaterniond(0, 0, 0)),
            Timestamp(MOVE,1.4)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-14.9, -1.67, 0),
            ignition::math::Quaterniond(0, 0, 1.75)),
            Timestamp(MOVE,2.8)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-6.5, -42.9, 0),
            ignition::math::Quaterniond(0, 0, 1.75)),
            Timestamp(MOVE,2.8)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(-2.5, -48, 0),
            ignition::math::Quaterniond(0, 0, 3.14)),
            Timestamp(MOVE,2.8)
          },
          std::pair<Spacestamp, Timestamp>{
            Spacestamp(ignition::math::Vector3d(46, -48, 0),
            ignition::math::Quaterniond(0, 0, 3.14)),
            Timestamp(MOVE,2.8)
          }
        };

        createTrajectory(trajectory);

        // set the animation
        _model->SetAnimation(_trajectory);
    }

    // Pointer to the model
    private: physics::ModelPtr _model;

  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedFoodTruck)
}
