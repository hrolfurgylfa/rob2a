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
|*                                         - Fjarstýring -                                            *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*                            Gerir kleyft að stjórna vélmenninu með fjartýringu                      *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Kalla fallið sem gerir kleyft að keyra vélmennið með fjarstýringunni                        *|
|*        	                                                                                          *|
|*    2)  Kalla fallið sem gerir kleyft að stýra arminum með fjarstýringunni                          *|
|*                                                                                                    *|
|*    3)  Kalla fallið sem gerir kleyft að stýra klónni með fjarstýringunni                           *|
|*                                                                                                    *|                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 1        left_motor          VEX 2-wire module     Left side motor                   *|
|*    Motor Port 6        claw_motor          VEX 3-wire module     claw motor                        *|
|*    Motor Port 7        arm_motor           VEX 3-wire module     arm motor                         *|
|*    Motor Port 10       right_motor         VEX 2-wire module     Right side motor                  *|            
\*----------------------------------------------------------------------------------------------------*/


//---------------------------------------|INCLUDES|-------------------------------------------------------------------------------------------------------

#include "../../includes/headers/rob2a_header.h"
#include "../../includes/functions/motorFunctions.c"

//----------------------------------------|Main|----------------------------------------------------------------------------------------------------------
task main(){
	while(true) {
		drive_controller(vexRT[Ch3], vexRT[Ch2], JOY_THREASHOLD);
		arm_controller(vexRT[Btn6U], vexRT[Btn6D]);
		claw_controller(vexRT[Btn5U], vexRT[Btn5D]);
	}
}
