//fallið drive_time lætur vélmennið keyra einhverra fjarðlægð fram eða til baka
void drive_time(float distance, bool forward, int BASETIME_METER){

	// Gerir hraðann annaðhvort plús tölu fyrir áfram (ef forward = true) eða mínus tölu til að fara til baka(ef forward = false)
	int speed = (forward)? (127):(-127);
	motor[right_motor] = speed; // segir hægri mótorinum að keyra
	motor[left_motor]  = speed; // segir mótorinum að keyra
	wait1Msec(distance * BASETIME_METER); // keyrir í sér tíma sem er reiknaður með breytunni distance og BASETIME_METER
}

void drive(float dist, bool forward, int BASE_DIST){
	SensorValue[quadrature_right] = 0;	  // Set the encoder so that it starts counting at 0
	SensorValue[quadrature_left]  = 0;	  // Set the encoder so that it starts counting at 0
	int speed100 =(forward)? (100):(-100);
	int speed74 =(forward)? (74):(-74);
	int speed127 =(forward)? (127):(-127);

	while(dist * BASE_DIST > abs(SensorValue[quadrature_right]))		// Creates an infinite loop, since "true" always evaluates to true
	{
		int motor_right_value = abs(SensorValue[quadrature_right]);
		int motor_left_value = abs(SensorValue[quadrature_left]);

		if(motor_right_value == motor_left_value) // If quadrature_right has counted the same amount as quadrature_left:
		{
			// Move Forward
			motor[right_motor] = speed100;		    // Right Motor is run at power level 80
			motor[left_motor]  = speed127;		    // Left Motor is run at power level 80
		}
		else if(motor_right_value > motor_left_value)	// If quadrature_right has counted more encoder counts
		{
			// Turn slightly right
			motor[right_motor] = speed74;		    // Right Motor is run at power level 60
			motor[left_motor]  = speed127;		    // Left Motor is run at power level 80
		}
		else	// Only runs if quadrature_left has counted more encoder counts
		{
			// Turn slightly left
			motor[right_motor] = speed127;		    // Right Motor is run at power level 80
			motor[left_motor]  = speed127;		    // Left Motor is run at power level 60
		}
	}
}

void keyra_begja(drive_turn_list, BASE_DEGREES_FOR_METER){
	for(int i = 0; i < sizeof(drive_turn_list)/sizeof(drive_turn_list[0]); i + 2) {
		bool forward = (drive_turn_list[i]>0)? (true):(false);
		drive(abs(drive_turn_list[i]), forward, BASE_DEGREES_FOR_METER);

		if (drive_turn_list[i+1] != 0) {
			bool direction = (drive_turn_list[i+1]>0)? (true):(false);
			turn(abs(drive_turn_list[i+1]), direction);
		}
	}
}