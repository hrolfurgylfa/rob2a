void drive_time(float distance, bool forward, int BASETIME_METER){

	int speed = (forward)? (127):(-127);
	motor[right_motor] = speed;
	motor[left_motor]  = speed;
	wait1Msec(distance * BASETIME_METER);
}
