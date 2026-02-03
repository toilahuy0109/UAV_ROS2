#include <uav_model.hpp>

UavModel::UavModel(double dt) : dt_(dt), x_(0.0), y_(0.0), z_(1.0), 
                                vx_(0.0), vy_(0.0), vz_(0.0),
                                ax_(0.0), ay_(0.0), az_(0.0) {}
                                
void UavModel::setCommand(double ax, double ay, double az)
{
    ax_ = ax;
    ay_ = ay;
    az_ = az;
}

void UavModel::step()
{
    // integrate velocity
    vx_ += ax_*dt_;
    vy_ += ay_*dt_;
    vz_ += az_*dt_;

    // integrate position
    x_ += vx_*dt_;
    y_ += vy_*dt_;
    z_ += vz_*dt_;
}

std::array<double, 6> UavModel::getState() const 
{
    return {x_, y_, z_, vx_, vy_, vz_};
}
