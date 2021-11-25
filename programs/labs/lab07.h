#include "attitude_estimator.h"
#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

// Define serial object
USBSerial serial;

// Define serial command variable
char command;

// Define attitude estimator object
AttitudeEstimator att_est;

// Define Ticker objects
Ticker tic, tic_range;

// Define Interrupt flag and count variables
bool flag, flag_range;

// Define Caalback functions
void callback() { flag = true; }
void callback_range() { flag_range = true; }

// Main program
int main()
{
    // Initialize attitude estimator objects
    att_est.init();

    // Initialize interrupt
    tic.attach(&callback, dt);
    tic_range.attach(&callback_range, dt_range);

    while (true)
    {
        // Estimate attitude
        if (flag)
        {
            flag = false;
            att_est.estimate();
            if ( flag_range )
            {
                flag_range = false ;
                serial.printf("%f, %f, %f\n",att_est.phi, att_est.theta, att_est.psi);
            }
        }    
    }
}