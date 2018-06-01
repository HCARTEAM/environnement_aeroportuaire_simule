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
  class AnimatedChassisPerson : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->model = _parent;

      double Zpos(model->GetWorldPose().pos.z);

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 200 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("animated_chassis_person", 174.478, false));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(-10.11, 11.729, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.1259));

        key = anim->CreateKeyFrame(0.1283);
        key->Translation(ignition::math::Vector3d(-10.119, 11.857, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -3.07));

        key = anim->CreateKeyFrame(4);
        key->Translation(ignition::math::Vector3d(-10.38, 15.72, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -3.07));

	key = anim->CreateKeyFrame(7);
        key->Translation(ignition::math::Vector3d(-10.38, 15.72, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -3.07));

        key = anim->CreateKeyFrame(8.832);
        key->Translation(ignition::math::Vector3d(-9.056, 16.987, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.134));

        key = anim->CreateKeyFrame(9.299);
        key->Translation(ignition::math::Vector3d(-8.92, 16.54, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.035));

        key = anim->CreateKeyFrame(10.09);
        key->Translation(ignition::math::Vector3d(-8.9, 15.75, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.035));

        key = anim->CreateKeyFrame(14.09);
        key->Translation(ignition::math::Vector3d(-8.9, 15.75, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.035));

        key = anim->CreateKeyFrame(14.32);
        key->Translation(ignition::math::Vector3d(-8.69, 15.652, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.292));

        key = anim->CreateKeyFrame(16.148);
        key->Translation(ignition::math::Vector3d(-6.93, 15.1648, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.2927));

        key = anim->CreateKeyFrame(17.007);
        key->Translation(ignition::math::Vector3d(-6.69, 14.34, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.336));

        key = anim->CreateKeyFrame(27.007);
        key->Translation(ignition::math::Vector3d(-6.69, 14.34, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.336));

        key = anim->CreateKeyFrame(31.06);
        key->Translation(ignition::math::Vector3d(-7.357, 10.337, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.1847));

        key = anim->CreateKeyFrame(31.96);
        key->Translation(ignition::math::Vector3d(-7.7974, 9.557, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.223));

        key = anim->CreateKeyFrame(33.2269);
        key->Translation(ignition::math::Vector3d(-8.988, 9.126, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -1.223));

	for (auto i = 34.062; i <= 134.062; i += 1)
		{
		    key = anim->CreateKeyFrame(i);
		    key->Translation(ignition::math::Vector3d(-9.8, 8.9311, Zpos));
		    key->Rotation(ignition::math::Quaterniond(0, 0, 0.0495));
		}

        key = anim->CreateKeyFrame(134.458);
        key->Translation(ignition::math::Vector3d(-9.42, 9.043, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.853));

        key = anim->CreateKeyFrame(135.798);
        key->Translation(ignition::math::Vector3d(-8.127, 9.395, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.835));

        key = anim->CreateKeyFrame(136.6486);
        key->Translation(ignition::math::Vector3d(-7.4, 9.836, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.063));

        key = anim->CreateKeyFrame(139.84);
        key->Translation(ignition::math::Vector3d(-7.15, 13.019, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.063));

	key = anim->CreateKeyFrame(141.8414);
        key->Translation(ignition::math::Vector3d(-7.15, 13.019, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.405));

	key = anim->CreateKeyFrame(151.8414);
        key->Translation(ignition::math::Vector3d(-7.15, 13.019, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.405));

	key = anim->CreateKeyFrame(152.84877);
        key->Translation(ignition::math::Vector3d(-7.452, 13.98, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.913));

	key = anim->CreateKeyFrame(154.618);
        key->Translation(ignition::math::Vector3d(-7.85, 15.704, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.913));

	key = anim->CreateKeyFrame(155.086);
        key->Translation(ignition::math::Vector3d(-8.316, 15.658, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -0.9324));

	key = anim->CreateKeyFrame(160.08);
        key->Translation(ignition::math::Vector3d(-8.316, 15.658, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -0.9324));

	key = anim->CreateKeyFrame(160.5159);
        key->Translation(ignition::math::Vector3d(-8.64, 15.94, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.51));

	key = anim->CreateKeyFrame(161.6425);
        key->Translation(ignition::math::Vector3d(-9.056, 16.987, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.134));

	key = anim->CreateKeyFrame(166.64);
        key->Translation(ignition::math::Vector3d(-9.056, 16.987, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, -2.134));

	key = anim->CreateKeyFrame(168.9635);
        key->Translation(ignition::math::Vector3d(-11.36, 16.707, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.1257));

	key = anim->CreateKeyFrame(173.449);
        key->Translation(ignition::math::Vector3d(-10.899, 12.245, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0.1257));

	key = anim->CreateKeyFrame(174.478);
        key->Translation(ignition::math::Vector3d(-9.95, 11.847, Zpos));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.495));




        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedFuelTruck)
}
