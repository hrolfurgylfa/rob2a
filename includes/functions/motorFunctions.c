//fallið drive_time lætur vélmennið keyra einhverra fjarðlægð fram eða til baka
void drive_time(float distance, bool forward, int BASETIME_METER){

	// Gerir hraðann annaðhvort plús tölu fyrir áfram (ef forward = true) eða mínus tölu til að fara til baka(ef forward = false)
	int speed = (forward)? (127):(-127);
	motor[right_motor] = speed; // segir hægri mótorinum að keyra
	motor[left_motor]  = speed; // segir mótorinum að keyra
	
	wait1Msec(distance * BASETIME_METER); // keyrir í sér tíma sem er reiknaður með breytunni distance og BASETIME_METER

	motor[right_motor] = 0;
	motor[left_motor] = 0;
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

	motor[right_motor] = 0;
	motor[left_motor]  = 0;
}

void drive_turn(int* drive_turn_list, int BASE_DEGREES_FOR_METER, float BASE_TURN){
	for(int i = 0; i < 30; i = i + 2) {
		int num_1 = drive_turn_list[i];
		int num_2 = drive_turn_list[i+1];
		writeDebugStream("Num 1: %d ",num_1);
		writeDebugStream("Num 2: %d ",num_2);
		writeDebugStream("i: %d ",i);

		bool forward;
		if (num_1 > 0){ forward = true; }
		else { forward = false; }

		float num_1_float = *(float *)&num_1;
		float drive_distance = abs(num_1_float) / 100;
		writeDebugStream("Afram: %f ",drive_distance);

		drive(drive_distance, forward, BASE_DEGREES_FOR_METER);
		wait1Msec(1000);

		if (num_2 != 0) {
			bool direction;
			if (num_2 > 0){ direction = true; }
			else { direction = false; }
			
			writeDebugStream("Begja: %d \n",abs(num_2));
			turn(abs(num_2), direction, BASE_TURN);
			wait1Msec(1000);
		}
	}
}

void turn(int deg, bool r_l, float BASE_TURN){

	if (r_l == true){

		SensorValue[quadrature_right] = 0;
		SensorValue[quadrature_left]  = 0;

		while(deg * BASE_TURN > abs(SensorValue[quadrature_right])){

			motor[right_motor] = -100;
			motor[left_motor] = 127;

		}
	}
	else if (r_l == false){

		SensorValue[quadrature_right] = 0;
		SensorValue[quadrature_left]  = 0;

		while(deg * BASE_TURN > abs(SensorValue[quadrature_left])){

			motor[right_motor] = 100;
			motor[left_motor] = -127;

		}
	}

	motor[right_motor] = 0;
	motor[left_motor] = 0;
}

void drive_controller(int left_forward, int right_forward, int threshold){
	if(abs(left_forward) > threshold) {
		motor[left_motor]  = (left_forward);   // Left Joystick Y value / 2.
		writeDebugStream("left_forward: %f \n",left_forward);
    } else {
      	motor[left_motor]  = 0;                // Stop the left motor (cancel noise)
    }

    if(abs(right_forward) > threshold) {
		motor[right_motor] = (right_forward);   // Right Joystick Y value / 2.
		writeDebugStream("right_forward: %f \n",right_forward);
    } else {
      	motor[right_motor] = 0;                // Stop the right motor (cancel noise)
    }
}