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
|*                                         - Sjálfkeyring -                                            *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*                            Gerir vélmenninu kleyft að keyra endalaust sjálfur                      *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Keyrir bara ef það er nógu bjart                                                            *|
|*        	                                                                                          *|
|*    2)  Keyrir áfram ef það er ekkert fyrir framan vélmennið                                        *|
|*                                                                                                    *|
|*    3)  Beygir ef það er eitthvað fyrir framan hann                                                 *|
|*                                                                                                    *|                                                                                                    
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 1        left_motor          VEX 2-wire module     Left side motor                   *|
|*    Motor Port 10       right_motor         VEX 2-wire module     Right side motor                  *|
|*    Sensor analog 1     light_sensor        VEX light sensor      Light sensor                      *|
|*    Sensor digital 10   sonar               VEX Sonar sensor      Sonar sensor                      *|
\*----------------------------------------------------------------------------------------------------*/


//---------------------------------------|INCLUDES|-------------------------------------------------------------------------------------------------------

#include "../includes/headers/rob2a_header.h"
#include "../includes/functions/motorFunctions.c"

//----------------------------------------|Main|----------------------------------------------------------------------------------------------------------
task main(){
	StartTask(emergency_stop);
    while (true) {
		if (SensorValue(light_sensor) < 250){
			if (SensorValue(sonar) > 70 || SensorValue(sonar) == -1) {
				motor[right_motor] = 127;
				motor[left_motor]  = 127;
			} else {
				motor[right_motor] = 127;
				motor[left_motor]  = -127;
			}
		}
		else {
			motor[right_motor] = 0;
			motor[left_motor]  = 0;
		}
	}
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
