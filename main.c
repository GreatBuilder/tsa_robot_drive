#pragma config(Motor,  port1,           right_wheel,   tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           right_forearm, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           left_forearm,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           claw_rotate,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           center_wheel,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          left_wheel,    tmotorVex393_HBridge, openLoop)

#include "JoystickDriver.c"

task main()
{
    wait1Msec(1000); // Wait for joystick to initialize
		int claw_power = 50;
    while(true)
    {
        // Move forward if Ch2 is positive
        if(vexRT[Ch2] > 10 {
            motor[left_wheel] = -127;
            motor[right_wheel] = -127;
        }
        // Move backward if Ch2 is negative
        else if(vexRT[Ch2] < -10){
            motor[left_wheel] = 127;
            motor[right_wheel] = 127;
        }
        // Stop if Ch2 is neutral
        else{
            motor[left_wheel] = 0;
            motor[right_wheel] = 0;
        }

        // Turning left or right with Ch1
        if(vexRT[Ch1] > 10) // Right turn
        {
            motor[left_wheel] = -127;
            motor[right_wheel] = 127;
        }
        else if(vexRT[Ch1] < -10) // Left turn
        {
            motor[left_wheel] = 127;
            motor[right_wheel] = -127;
        }

        // Move the base rotate right
        if(vexRT[Ch3] < -10) // Adding a deadzone to prevent minor joystick movements
        {
            motor[base_rotate] = -claw_rotate_power;  // Move base rotate counter-clockwise
            motor[claw_rotate] = claw_rotate_power;  // Move claw rotate counter-clockwise
        }
        // Move the base rotate right
        else if(vexRT[Ch3] > 10) // Adding a deadzone to prevent minor joystick movements
        {
            motor[base_rotate] = claw_rotate_power;  // Move base rotate clockwise
            motor[claw_rotate] = -claw_rotate_power;  // Move claw rotate clockwise
        }
        // Stop if Ch3 is neutral
        else
        {
            motor[base_rotate] = 0;
            motor[claw_rotate] = 0;
        }

        // Move the claw open right
        if(vexRT[Btn8U] == 1) // Adding a deadzone to prevent minor joystick movements
        {
            motor[claw_open] = -30;  // Move claw open counter-clockwise
        }
        // Move the base open right
        else if(vexRT[Btn8D] == 1) // Adding a deadzone to prevent minor joystick movements
        {
            motor[claw_open] = 30;  // Move claw open clockwise
        }
        // Stop if Btn8D or Btn8U is neutral
        else
        {
            motor[claw_rotate] = 0;
        }
    }
}
