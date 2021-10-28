#include "attitude_controller.h"

// Class constructor
AttitudeController::AttitudeController()
{
    tau_phi = 0.0;
    tau_theta = 0.0;
    tau_psi = 0.0;
}

// Control torques (N.m) given reference angles (rad) and current angles (rad) and angular velocities (rad/s)
void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta , float psi , float p, float q, float r)
{

    float alfa_phi = control_siso(phi_r, phi, p, kp_row, kd_row);
    float alfa_theta = control_siso(theta_r, theta, q, kp_pitch, kd_pitch);
    float alfa_psi = control_siso(psi_r, psi, r, kp_yaw, kd_yaw);

    tau_phi = I_xx * alfa_phi;
    tau_theta = I_yy * alfa_theta;
    tau_psi = I_zz * alfa_psi;
}

// Control torque (N.m) given reference angle (rad) and current angle (rad) and angular velocity (rad/s) with given controller gains
float AttitudeController::control_siso(float angle_r, float angle, float rate, float kp, float kd)
{
    return kp*(angle_r - angle) + kd*(0 - rate);
}
