#include "mixer.h"


// Class constructor
Mixer::Mixer() : motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4),
armed(false),
motor_1_RED_LED(LED_RED_R,!false), motor_1_GREEN_LED(LED_GREEN_R,!false),
motor_3_BLUE_LED(LED_BLUE_L,false),
motor_4_RED_LED(LED_RED_L,!false), motor_4_GREEN_LED(LED_GREEN_L,!false)
{
    motor_1.period(1.0/500.0);
    motor_2.period(1.0/500.0);
    motor_3.period(1.0/500.0);
    motor_4.period(1.0/500.0);
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
    disarm_LEDs();
}

// Arm mixer
void Mixer::arm()
{
    armed = true;
    arm_LEDs();
}

// Disarm mixer
void Mixer::disarm()
{
    armed = false;

    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;

    disarm_LEDs();    
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    if (armed==true) {
        mixer(f_t,tau_phi,tau_theta,tau_psi);
        motor_1 = control_motor(omega_1);
        motor_2 = control_motor(omega_2);
        motor_3 = control_motor(omega_3);
        motor_4 = control_motor(omega_4);
    }
}

// Convert total trust force (N) and torques (N.m) to angular velocities (rad/s)
void Mixer::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    omega_1 = sqrt(f_t/(4*kl) - tau_phi/(4*kl*l) - tau_theta/(4*kl*l) - tau_psi/(4*kd));
    omega_2 = sqrt(f_t/(4*kl) - tau_phi/(4*kl*l) + tau_theta/(4*kl*l) + tau_psi/(4*kd));
    omega_3 = sqrt(f_t/(4*kl) + tau_phi/(4*kl*l) + tau_theta/(4*kl*l) - tau_psi/(4*kd));
    omega_4 = sqrt(f_t/(4*kl) + tau_phi/(4*kl*l) - tau_theta/(4*kl*l) + tau_psi/(4*kd));
}

// Convert desired angular velocity (rad/s) to PWM signal (%)
float Mixer::control_motor(float omega)
{
    float pwm = a2_pwm*pow(omega, 2) + a1_pwm*omega + a0_pwm;
    return pwm;
}

//LEDs arm
void Mixer::arm_LEDs()
{
    motor_1_RED_LED = !true;
    motor_4_RED_LED = !true;

    motor_1_GREEN_LED = !true;
    motor_4_GREEN_LED = !true;

    for (int i=0; i<10; i++) {
        motor_1_RED_LED = !motor_1_RED_LED;
        motor_4_RED_LED = !motor_4_RED_LED;

        motor_1_GREEN_LED = !motor_1_GREEN_LED;
        motor_4_GREEN_LED = !motor_4_GREEN_LED;
        wait(0.5);
    }

    motor_1_RED_LED = !true;
    motor_4_RED_LED = !true;

    motor_1_GREEN_LED = !false;
    motor_4_GREEN_LED = !false;
}

//LEDs disarm
void Mixer::disarm_LEDs()
{
    motor_1_RED_LED = !false;
    motor_4_RED_LED = !false;

    motor_1_GREEN_LED = !true;
    motor_4_GREEN_LED = !true;
}