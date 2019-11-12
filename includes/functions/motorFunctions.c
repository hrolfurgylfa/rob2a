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

// drive fallið lætur vélmennið keyra ákveðna fjarægð, afturábak eða áfram en er mun nákvæmara en drive_time og róbótinn begir ekki
void drive(float dist, bool forward, int BASE_DIST){
	SensorValue[quadrature_right] = 0;	  // quadrature_right skynjarinn settur á 0 svo að það sé hgt að nota það í reikningana
	SensorValue[quadrature_left]  = 0;	  // quadrature_left skynjarinn settur á 0 svo að það sé hgt að nota það í reikningana
	// Þetta eru mismunandi variables vegna þess að annars begir róbótinn of mikið og nær ekki að rétta sig almennilega
	int speed100 =(forward)? (100):(-100);// Átt reiknuð fyrir 100 hraðann
	int speed74 =(forward)? (74):(-74);// Átt reiknuð fyrir 74 hraðann
	int speed127 =(forward)? (127):(-127);// Átt reiknuð fyrir 127 hraðann

	// Þetta keyrir þangað til quadrature_right skynjarinn segir að það sé búið að keyra nógu langt
	while(dist * BASE_DIST > abs(SensorValue[quadrature_right])) {

		// Hérna geymum við quadrature outputtið í variables til þess að þurfa ekki alltaf að reikna absaloute value
		int motor_right_value = abs(SensorValue[quadrature_right]);
		int motor_left_value = abs(SensorValue[quadrature_left]);

		// Þetta keyrir ef róbótinn er að keyra þráð beint
		if(motor_right_value == motor_left_value){
			motor[right_motor] = speed100;
			motor[left_motor]  = speed127;
		}
		// Þetta keyrir ef róbótinn er að begja til vinstri
		else if(motor_right_value > motor_left_value){
			motor[right_motor] = speed74;
			motor[left_motor]  = speed127;
		}
		// Þetta keyrir ef rúbótinn er að begja til hægri
		else {
			motor[right_motor] = speed127;
			motor[left_motor]  = speed127;
		}
	}

	// Hérna er róbótinn búinn svo að hann stoppar báða mótorana
	motor[right_motor] = 0;
	motor[left_motor]  = 0;
}

// Þetta fall takur inn lista af fyrst fjarlægð í cm og svo gráðum til þess að begja og keyrir eftir honum: [cm, degrees, cm, degrees]
void drive_turn(int* drive_turn_list, int BASE_DEGREES_FOR_METER, float BASE_TURN, int arrey_length){
	// Hérna nota ég variable sem var sent inn í fallið, arrey_length, vegna þess að það er ekki hægt að ná lengdini af pointer list
	for(int i = 0; i < arrey_length; i = i + 2) {
		int num_1 = drive_turn_list[i];// Þetta er talan hversu mikið á að keyra
		int num_2 = drive_turn_list[i+1];// Þetta er talan hversu mikið á að begja
		// writeDebugStream("Num 1: %d ",num_1);
		// writeDebugStream("Num 2: %d ",num_2);
		// writeDebugStream("i: %d ",i);

		bool forward;// Þessi bool segir hvort að róbótinn eigi að fara afturábak eða áfram, þetta er svo sent inn í fallið drive();
		// Hérna er ákveðið hvort að forward eigi að vera true eða false eftir því hvort num_1 (fjarlægðin sem á að keyra) sé í mínus eða plús
		if (num_1 > 0){ forward = true; }
		else { forward = false; }

		// Hérna er breytt num_1 í float og sett í num_1_float
		float num_1_float = *(float *)&num_1;
		// Drive distance reiknað vegna þess að það kom inn í þetta fall sem cm en þarf að vera metrar fyrir drive() fallið
		float drive_distance = abs(num_1_float) / 100;
		// writeDebugStream("Afram: %f ",drive_distance);

		// Drive fallið kallað
		drive(drive_distance, forward, BASE_DEGREES_FOR_METER);
		wait1Msec(1000);// Hérna er beðið svo að róbótinn verði nákvæmari þegar hann er að keyra brautina

		// Þetta keyrir bara ef snúningurinn er ekki 0
		if (num_2 != 0) {
			bool direction;// Þessi bool segir hvort að róbótinn eigi að begja til hægri eða vinstri, þetta er svo sent inn í fallið turn()
			// Hérna er ákveðið hvort að direction eigi að vera true eða false eftir því hvort num_2 (snúningurinn) sé í mínus eða plús
			if (num_2 > 0){ direction = true; }
			else { direction = false; }

			// writeDebugStream("Begja: %d \n",abs(num_2));
			turn(abs(num_2), direction, BASE_TURN);// Turn fallið keyrt
			wait1Msec(1000);// Hérna er beðið svo að róbótinn verði nákvæmari þegar hann er að keyra brautina
		}
	}
}

void turn(int deg, bool r_l, float BASE_TURN){

	// Róbótinn á að begja til hægri
	if (r_l == true){

		SensorValue[quadrature_right] = 0;
		SensorValue[quadrature_left]  = 0;

		while(deg * BASE_TURN > abs(SensorValue[quadrature_right])){

			motor[right_motor] = -100;
			motor[left_motor] = 127;

		}
	}
	// Róbótinn á að begja til vinstri
	else if (r_l == false){

		SensorValue[quadrature_right] = 0;
		SensorValue[quadrature_left]  = 0;

		while(deg * BASE_TURN > abs(SensorValue[quadrature_left])){

			motor[right_motor] = 100;
			motor[left_motor] = -127;

		}
	}

	// Hérna er róbótinn búinn svo að hann stoppar báða mótorana
	motor[right_motor] = 0;
	motor[left_motor] = 0;
}

void drive_controller(int left_forward, int right_forward, int threshold){
	if(abs(left_forward) > threshold) {
		motor[left_motor]  = (left_forward);   // Left Joystick Y value / 2.
		// writeDebugStream("left_forward: %f \n",left_forward);
    } else {
      	motor[left_motor]  = 0;                // Stop the left motor (cancel noise)
    }

    if(abs(right_forward) > threshold) {
		motor[right_motor] = (right_forward);   // Right Joystick Y value / 2.
		// writeDebugStream("right_forward: %f \n",right_forward);
    } else {
      	motor[right_motor] = 0;                // Stop the right motor (cancel noise)
    }
}

void arm_controller(int upp_btn, int down_btn) {
	if (upp_btn == 1 && down_btn == 1){
		motor[arm_motor] = 0;
	}
	else if (upp_btn == 1){
		motor[arm_motor] = 100;
	}
	else if (down_btn == 1){
		motor[arm_motor] = -100;
	}
	else {
		motor[arm_motor] = 0;
	}
}

void claw_controller(int close_btn, int open_btn) {
	if (open_btn == 1 && close_btn == 1) {
		motor[claw_motor] = 0;
	}
	else if (open_btn == 1){
		motor[claw_motor] = 100;
	}
	else if (close_btn == 1){
		motor[claw_motor] = -100;
	}
	else {
		motor[claw_motor] = 0;
	}
}

void drive_line(int speed, int threshold) {
	while(true) {

		int rightSeeLine = SensorValue(line_follower_right) > threshold;
		int leftSeeLine = SensorValue(line_follower_left) > threshold;
		int middleSeeLine = SensorValue(line_follower_middle) > threshold;

		// Ef myðju skynjarinn sér eitthvað þá heldur róbotinn bara áfram
		if(middleSeeLine) {
			writeDebugStream("Keyri beint\n");
			// go straight
			motor[left_motor] = speed;
			motor[right_motor] = speed;
		}

		// Right sensor sér ekki línu en left sensor sér línu
		else if(!rightSeeLine && (leftSeeLine || middleSeeLine)) {
			writeDebugStream("Beygi til haegri\n");
			// Begja til vinstri
			motor[left_motor] = 0;
			motor[right_motor] = speed;
		}
		// Left sensor sér ekki línu en right sensor sér línu
		else if(!leftSeeLine && (rightSeeLine || middleSeeLine)) {
			writeDebugStream("Beygi til vinstri\n");
			// Begja til hægri
			motor[left_motor] = speed;
			motor[right_motor] = 0;
		}
		// Línan er búin
		else {
			motor[left_motor] = 0;
			motor[right_motor] = 0;
			break;
		}
	}
}