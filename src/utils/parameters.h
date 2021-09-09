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

// Angular velocity parameters
// Lab2
const float a2_pwm = 1.16e-07;
const float a1_pwm = 4.488e-12;
const float a0_pwm = 0;

// Constante de sustentacao
// Lab3
const float kl = 1.726e-08;

// Constante de arrasto
// Lab4
const float kd = 1.313e-10;

#endif