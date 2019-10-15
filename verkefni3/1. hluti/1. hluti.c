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

//---------------------------------------|INCLUDES|-------------------------------------------------------------------------------------------------------

#include "../../includes/headers/rob2a_header.h"
#include "../../includes/functions/motorFunctions.c"

//----------------------------------------|Main|----------------------------------------------------------------------------------------------------------
task main(){
	while(true) {
		drive_controller(vexRT[Ch3], vexRT[Ch2], JOY_THREASHOLD);
		writeDebugStream("Arm up: %d ",vexRT[Btn6U]);
		writeDebugStream("Arm down: %d \n",vexRT[Btn6D]);
		arm_controller(vexRT[Btn6U], vexRT[Btn6D]);
		claw_controller(vexRT[Btn5U], vexRT[Btn5D]);
	}
}
