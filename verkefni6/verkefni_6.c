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
/*----------------------------------------------------------------------------------------------------*\
|*                             	    - Triple Sensor Line Tracking -                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*                                  Eltir svarta línu á hvítu yfirborði                               *|
|*                                        															  *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Notar fallið drive_line sem tekur inn LINE_THRESHOLD sem er reiknað út áður.                *|
|*    2)  LINE_THRESHOLD er constant breyta sem myndi vera æskilegt að breyta eftir aðstæðum.         *|
|*          																						  *|
|*               																					  *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor  - Port 2     rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor  - Port 3     leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Analog - Port 1     lineFollowerRIGHT   VEX Light Sensor      Front-right, facing down          *|
|*    Analog - Port 2     lineFollowerCENTER  VEX Light Sensor      Front-center, facing down         *|
|*    Analog - Port 3     lineFollowerLEFT    VEX Light Sensor      Front-left, facing down           *|
\*----------------------------------------------------------------------------------------------------*/


//---------------------------------------|INCLUDES|-------------------------------------------------------------------------------------------------------

#include "../includes/headers/rob2a_header.h"
#include "../includes/functions/motorFunctions.c"

//----------------------------------------|Main|----------------------------------------------------------------------------------------------------------
task main(){
	StartTask(emergency_stop);

    drive_line_distance(2, 60, BASE_DEGREES_FOR_METER, LINE_THREASHOLD);
    finna_glas(0, 1000);
    drive_line_distance(2, 60, BASE_DEGREES_FOR_METER, LINE_THREASHOLD);
    sleppa_glasi(0, 1000);
}

task emergency_stop(){
	while(true){
		if (sensorValue[front_button] == 1 || vexRT[Btn7U] == 1){
			break;
		}
	}
	writeDebugStream("Stopping!!!\n");
	StopAllTasks();
}
