#include "mbed.h"
#include "crazyflie.h"
#include "parameters.h"

// Define motor 1 as PWM output object
PwmOut motor1(MOTOR1);

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(float omega_r) {
    float pwm = a2_pwm*pow(omega_r, 2) + a1_pwm*omega_r + a0_pwm;
    return pwm;
}

// Main program
int main() {
    // Set PWM frequency to 500Hz
    motor1.period(1.0/500.0);

    // Turn on motor 1 with 1.000 rad/s for 0.5s
    motor1 = control_motor(1000.0);
    wait(3);

    // Turn off motor 1
    motor1 = 0.0;

    // End of program
    while(true) {
    }
}