#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut m1_r(LED_RED_R,!false);
DigitalOut m1_g(LED_GREEN_R,!false);

DigitalOut m3_b(LED_BLUE_L,false);

DigitalOut m4_r(LED_RED_L,!false);
DigitalOut m4_g(LED_GREEN_L,!false);

// Define all motors as PWM objects
PwmOut motor_1(MOTOR1);
PwmOut motor_2(MOTOR2);
PwmOut motor_3(MOTOR3);
PwmOut motor_4(MOTOR4);

// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    for (int i=0; i<10; i++) {
        m3_b = !m3_b;
        wait(0.5);
    }
    m3_b = false;

    // Turn on red LEDs indicating motors are armed
    m1_r = !m1_r;
    m4_r = !m4_r;
    wait(1);

    // Test all motors with different frequencies (to make different noises)
    motor_1 = 0.2;
    motor_1.period(1.0/400);
    wait(3);
    motor_1 = 0;

    motor_2 = 0.2;
    motor_2.period(1.0/600);
    wait(3);
    motor_2 = 0;

    motor_3 = 0.2;
    motor_3.period(1.0/800);
    wait(3);
    motor_3 = 0;

    motor_4 = 0.2;
    motor_4.period(1.0/1000);
    wait(3);
    motor_4 = 0;
    
    // Turn off red LEDs indicating motors are disarmed
    m1_r = !m1_r;
    m4_r = !m4_r;

    // Blink green LEDs indicating end of program
    while(true)
    {
        m1_g = !m1_g;
        m4_g = !m4_g;
        wait(0.5);
    }
}
