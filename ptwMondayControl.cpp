#include "ptwHeader.h"

using namespace std;

// NEVER CHANGE I AND J VALUE OUTSIDE SENSORREAD, AFTER INITIATION
int main() {
    
    // start ttyACM
    int extArr
    char reqArr;
    
    ptwClass ptw;

    ptw.gameState = true;

    // error checks
    while (ptw.gameState != false) {

    wiringPiSetup();
	if ((extArr = serialOpen("/dev/ttyACM0", 115200)) < 0) {
		fprintf (stderr, "Could not open USB: %s\n", strerror(errno));
		return 1; 
			
	}

	if (wiringPiSetup () == -1) {
		fprintf (stdout, "Unable to open WiringPi: %s\n", strerror(errno));
		return 1;
		
	}	

    // set up sensor read
	reqArr = 'a';
	
	serialPutchar(extArr, reqArr);
	
    // sensor read runs everything from here
    ptw.sensorRead();
    }
}
