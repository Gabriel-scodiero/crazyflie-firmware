#include "attitude_estimator.h"
#include <cmath>

// Class constructor
AttitudeEstimator::AttitudeEstimator() : imu(IMU_SDA,IMU_SCL)
{

}

// Initialize class
void AttitudeEstimator::init()
{
    imu.init();

    // Calibrar giroscópio
    float gx_total;
    float gy_total;
    float gz_total;
    for(int i=0; i<500;i++) {
        imu.read();
        gx_total += imu.gx;
        gy_total += imu.gy;
        gz_total += imu.gz;
        wait(dt);
    }
    p_bias = gx_total/500;
    q_bias = gy_total/500;
    r_bias = gz_total/500;
    
}

// Estimate Euler angles (rad) and angular velocities (rad/s)
void AttitudeEstimator::estimate()
{
    imu.read();

    float phi_old = phi;
    float theta_old = theta;
    float psi_old = psi;

    p = imu.gx - p_bias;
    q = imu.gy - q_bias;
    r = imu.gz - r_bias;

    float phi_a = atan2(-imu.ay, -imu.az);
    float theta_a = atan2(imu.ax, -((imu.az>0)-(imu.az<0))*sqrt(pow(imu.ay,2) + pow(imu.az,2)) );

    float phi_g = phi_old + ( p + sin(phi_old)*tan(theta_old)*q + cos(phi_old)*tan(theta_old)*r )*dt;
    float theta_g = theta_old + ( cos(phi_old)*q - sin(phi_old)*r )*dt;
    float psi_g = psi_old + ( sin(phi_old)*(1/cos(theta_old))*q + cos(phi_old)*(1/cos(theta_old))*r )*dt;
    
    phi = phi_g*(1-alfa) + phi_a*alfa;
    theta = theta_g*(1-alfa) + theta_a*alfa;
    psi = psi_g;
}