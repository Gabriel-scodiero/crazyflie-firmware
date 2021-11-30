# include "vertical_controller.h"

// Class constructor
VerticalController::VerticalController()
{
    f_t = 0.0;
}

// Control thrust force (N) given vertical position (m) and velocity (m/s)
void VerticalController::control (float z_r, float z, float w)
{
    float acc_z = control_siso(z_r, z, w, kp_z, kd_z);
    f_t = m*(g + acc_z);
}

// Control aceleration given reference position (m) and current position (m) and velocity (m/s) with given controller gains
float VerticalController::control_siso(float pos_r, float pos, float vel, float kp, float kd)
{
    return float(kp*(pos_r - pos) + kd*(vel));
}