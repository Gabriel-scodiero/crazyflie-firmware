#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

// Lab2
// Angular velocity parameters
const float a2_pwm = 1.16e-07;
const float a1_pwm = 4.488e-12;
const float a0_pwm = 0;

// Lab3
// Constante de sustentacao
const float kl = 1.726e-08;

// Lab4
// Constante de arrasto
const float kd = 1.313e-10;

// Lab7
// Intervalo tempo estimador atitude
const float dt = 1.0/500;
// Filtro passa baixa
const float wc = 1;
const float alfa = (wc*dt)/(1+(wc*dt));

// Lab8
// Ganhos controlador atitude (row)
const float OS_row = 0.005;
const float Ts_row = 0.3;
const float zeta_row = abs(log(OS_row))/sqrt(pow(log(OS_row),2) + pow(pi,2));
const float wn_row = 4/(zeta_row*Ts_row);
const float kp_row = pow(wn_row,2);
const float kd_row = 2*zeta_row*wn_row;
// Ganhos controlador atitude (pitch)
const float kp_pitch = kp_row;
const float kd_pitch = kd_row;
// Ganhos controlador atitude (yaw)
const float OS_yaw = 0.005;
const float Ts_yaw = 0.6;
const float zeta_yaw = abs(log(OS_yaw))/sqrt(pow(log(OS_yaw),2) + pow(pi,2));
const float wn_yaw = 4/(zeta_yaw*Ts_yaw);
const float kp_yaw = pow(wn_yaw,2);
const float kd_yaw = 2*zeta_yaw*wn_yaw;

// Lab9
// Intervalo tempo estimador vertical
const float dt_range = 1.0/20;
// Filtro passa baixa
const float wc_vert = 10;
const float amort = sqrt(2)/2;
const float l1 = pow(wc_vert,2);
const float l2 = 2*wc_vert*amort;

// Lab10
// Ganhos controlador vertical
const float OS_z = 0.005;
const float Ts_z = 2;
const float zeta_z = abs(log(OS_z))/sqrt(pow(log(OS_z),2) + pow(pi,2));
const float wn_z = 4/(zeta_z*Ts_z);
const float kp_z = pow(wn_z,2);
const float kd_z = 2*zeta_z*wn_z;

// Lab11
// Parâmetros sensor estimador valocidade horizontal
const float sigma = (2*tan((42*pi/180)/2))/(420*dt);
// Filtro passa baixa
const float wc_hor = 50;
const float l3 = wc_hor;

// Lab12
// Ganhos controlador horizontal (x)
const float kp_x = kp_z;
const float kd_x = kd_z;
// Ganhos controlador horizontal (y)
const float kp_y = kp_z;
const float kd_y = kd_z;


#endif