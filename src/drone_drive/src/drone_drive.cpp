#include <drone_drive/drone_drive.hpp>
#include <gazebo/common/Events.hh>
#include <ignition/math/Vector3.hh>
#include <cmath>

namespace gazebo{
    GZ_REGISTER_MODEL_PLUGIN(DroneDiffDrivePlugin)

    DroneDiffDrivePlugin::DroneDiffDrivePlugin()
        :   linear_x_(0.0), linear_z_(0.0), angular_z_(0.0),
            k_thrust_(0.0005), k_yaw_(0.0001), k_forward_(0.5),
            max_rotor_vel_(100.0),arm_length_(0.4){}
  
    void DroneDiffDrivePlugin::Load(physics::ModelPtr model, sdf::ElementPtr sdf)
    {
        model_ = model;

        // Get base_link

        base_link_ = model_->GetLink("base_link");
        if(!base_link_){
            gzerr << "ERROR: Link 'base_link' not found in model \n";
            return;
        }

        //Load parameters from SDF

        if(sdf->HasElement("robot_namespace")){
            cmd_topic_ = sdf->Get<std::string>("robot_namespace") + "/diff_drive";
        }else{
            cmd_topic_ = "/drone/diff_drive";
        }

        
    }
}