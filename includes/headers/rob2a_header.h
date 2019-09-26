#ifndef rob2a_header
#define rob2a_header
#endif

//-----------------------------|define variables|------------------------------------------------
const int BASETIME_METER = 3400;
const int FULLPOWER = 127;
const int BASE_DEGREES_FOR_METER = 1080;

//---------------------------|initialize functions|--------------------------------------------

void drive_time(float distance, bool forward, int BASETIME_METER);
void drive(float dist, bool forward, int BASE_DIST);
void turn(int deg, bool r_l);
void drive_turn(int* drive_turn_list, int BASE_DEGREES_FOR_METER);
