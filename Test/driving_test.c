#pragma config(Sensor, in1,    light_sensor,   sensorReflection)
#pragma config(Sensor, in2,    line_follower_left, sensorLineFollower)
#pragma config(Sensor, in3,    line_follower_middle, sensorLineFollower)
#pragma config(Sensor, in4,    line_follower_right, sensorLineFollower)
#pragma config(Sensor, in5,    arm_potentiometer, sensorPotentiometer)
#pragma config(Sensor, dgtl5,  quadrature_left, sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  quadrature_right, sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  safety_switch,  sensorTouch)
#pragma config(Sensor, dgtl10, sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl12, front_button,   sensorTouch)
#pragma config(Motor,  port1,           left_motor,    tmotorVex269, openLoop, reversed, encoder, encoderPort, dgtl5, 1000)
#pragma config(Motor,  port6,           claw_motor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           arm_motor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,          right_motor,   tmotorVex269, openLoop, encoder, encoderPort, dgtl7, 1000)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs your robot to move forward at full power for three seconds.  There is a    *|
|*  two second pause at the beginning of the program.                                                 *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Power levels that can be assigned to a motor port range from -127 (full reverse) to         *|
|*        127 (full forward).                                                                         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 2        rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor Port 3        leftMotor           VEX 3-wire module     Left side motor                   *|
\*-----------------------------------------------------------------------------------------------4246-*/


void drive_time(float distance, bool forward, int BASETIME){
	int speed = (forward)? (127):(-127);
	motor[right_motor] = speed;
	motor[left_motor]  = speed;
	wait1Msec(distance * BASETIME);
}
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	drive_time(0.25, false, 1700*2);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
