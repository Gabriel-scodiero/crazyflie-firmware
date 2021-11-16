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
// Ganhos proporcionais controladores angulares
const float kp_row = 240.2808379;
const float kp_pitch = kp_row;
const float kp_yaw = 60.07020954;
// Ganhos derivativos controladores angulares
const float kd_row = 26.66666665;
const float kd_pitch = kd_row;
const float kd_yaw = 13.33333333;

// Lab9
// Intervalo tempo estimador vertical
const float dt_range = 1.0/20;
// Filtro passa baixa
const float wc_vert = 10;
const float amort = sqrt(2)/2;
const float l1 = pow(wc_vert,2);
const float l2 = 2*wc_vert*amort;

#endif