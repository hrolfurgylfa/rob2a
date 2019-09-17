//fallið drive_time lætur vélmennið keyra einhverra fjarðlægð fram eða til baka
void drive_time(float distance, bool forward, int BASETIME_METER){

	// Gerir hraðann annaðhvort plús tölu fyrir áfram (ef forward = true) eða mínus tölu til að fara til baka(ef forward = false)
	int speed = (forward)? (127):(-127);
	motor[right_motor] = speed; // segir hægri mótorinum að keyra
	motor[left_motor]  = speed; // segir mótorinum að keyra
	wait1Msec(distance * BASETIME_METER); // keyrir í sér tíma sem er reiknaður með breytunni distance og BASETIME_METER
}
