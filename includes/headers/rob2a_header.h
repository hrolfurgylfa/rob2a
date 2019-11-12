#ifndef rob2a_header
#define rob2a_header
#endif

//-----------------------------|define variables|------------------------------------------------
const int BASETIME_METER = 3400;
const int FULLPOWER = 127;
const int BASE_DEGREES_FOR_METER = 1080;
const float BASE_TURN = 3;
const int JOY_THREASHOLD = 10;

//---------------------------|initialize functions|--------------------------------------------

void drive_time(float distance, bool forward, int BASETIME_METER);
void drive(float dist, bool forward, int BASE_DIST);
void drive_turn(int* drive_turn_list, int BASE_DEGREES_FOR_METER, int arrey_length);
void turn(int deg, bool r_l, float BASE_TURN);
void drive_controller(int left_forward, int right_forward);
void drive_line(int speed, int threshold);
task emergency_stop();