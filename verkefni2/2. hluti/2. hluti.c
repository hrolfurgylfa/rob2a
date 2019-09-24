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
    // Bíða 2 sec
	//wait1Msec(2000);
	turn(360, true);
	turn(360, false);
	/*wait1Msec(2000);
	motor[left_motor] = -127;
	motor[right_motor] = -127;
	wait1Msec(2000);*/


/*
	//for lykkjan hækkar distance bryetuna um 0.5 þangað til að hún er komin í 2.5
	for(float distance = 0.5; distance <= 2.5; distance += 0.5){
		drive(distance, true, BASE_DEGREES_FOR_METER); //lætur vélmennið keyra áfram 1 metra með því að keyra fallið drive
		drive(distance, false, BASE_DEGREES_FOR_METER); //lætur vélmennið keyra afturábak 1 metra með því að keyra fallið drive
	}
	*/
}
