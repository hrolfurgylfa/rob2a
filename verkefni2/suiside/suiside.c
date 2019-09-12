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

//#include "../../includes/headers/rob2a_header.h"
//#include "../../includes/functions/motorFunctions.inc"

#define BASETIME_METER 3400
#define FULLPOWER 127

void drive_time(float distance, bool forward, int BASETIME_METER){

	int speed = (forward)? (127):(-127);
	motor[right_motor] = speed;
	motor[left_motor]  = speed;
	wait1Msec(distance * BASETIME_METER);
}

task main(){

	wait1Msec(2000);
	for(float distance = 0.5; distance <= 2.5; distance += 0.5){
		drive_time(distance, true, BASETIME_METER);
		drive_time(distance, false, BASETIME_METER);
	}
}
