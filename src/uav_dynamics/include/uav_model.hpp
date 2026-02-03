// Mathematics Model for UAV

#pragma once

#include <array>

class UavModel {
    public:
    UavModel(double dt);    // dt: sampling time

    void setCommand(double ax, double ay, double az);
    void step();
    
    std::array<double, 6> getState() const;

    private:
    double dt_;

    // state
    double x_, y_, z_;
    double vx_, vy_, vz_;

    // input
    double ax_, ay_, az_;
};