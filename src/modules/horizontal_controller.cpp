#include "horizontal_controller.h"
#include "parameters.h"

// Class constructor
HorizontalController::HorizontalController()
{
    phi_r = 0.0;
    theta_r = 0.0;
}

// Control reference roll and pitch angles (rad) given reference positions (m) and current positions (m) and velocities (m/s)
void HorizontalController::control(float x_r , float y_r , float x, float y, float u, float v)
{
    float acc_x = control_siso(x_r, x, u, kp_x, kd_x);
    float acc_y = control_siso(y_r, y, v, kp_y, kd_y);
    phi_r = acc_x/g;
    theta_r = -acc_y/g;
}

// Control acceleration given reference position (m) and current position (m) and velocity (m/s) with given controller gains
float HorizontalController::control_siso(float pos_r, float pos, float vel, float kp, float kd)
{
    return kp*(pos_r - pos) + kd*(0 - vel);
}