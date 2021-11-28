#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <iostream>


#include <wiringPi.h>
#include <wiringSerial.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

int main () {

int extArr; 
//int extArrData;
//int ptwCycle;
//unsigned int ptwCycleTime;
unsigned char reqArr;
// int charToInt;

// loop and array stuff
int i, j;
int cols = 11;
int rows = 8;
char cArr[1000];
int i2dArr [8][11];
// char numArr[loopSize];

// string to int conv
char sArrFeed;
int iArrFeed;


wiringPiSetup();

	if ((extArr = serialOpen("/dev/ttyACM0", 115200)) < 0) {
		
		fprintf (stderr, "Could not open USB: %s\n", strerror(errno));
		return 1; 
			
	}


	if (wiringPiSetup () == -1) {
		
		fprintf (stdout, "Unable to open WiringPi: %s\n", strerror(errno));
		return 1;
		
	}	
	
	reqArr = 'a';
	
	// extArrData = serialDataAvail(extArr);
	
	serialPutchar(extArr, reqArr);
	
	while (!serialDataAvail(extArr)) {
		;
	}
	j = 0;
	i = 0;
	
	while ((sArrFeed = serialGetchar(extArr)) != '\n') {
		
		// cout << "GetChar gets " << (char)serialGetchar(extArr);

		
		// sArrFeed = serialGetchar(extArr);
					
		cArr[i] = sArrFeed;
		
		cout << cArr[i];
					
		i++;
		
		// serialGetchar(extArr);
			
			/* do  {
					
					sArrFeed = serialGetchar(extArr);
					
					cArr[i] = sArrFeed;
				
					// if (cArr[i] == 44) {
					//				
					// }
				
					iArr[i] = cArr[i] - 48;
					
					cout << cArr[i];
					
					i++;
					
			} while (sArrFeed != '\n');
		
		cout << '\n'; 
		
		/*
		for (i = 0; i < loopSize; i++) {
		
			charArr[i] = serialGetchar(extArr); 
			// cout << charArr[i] << " ";
		
			numArr[i]; 
			cout << "Int val: " << numArr[i] << endl;
			
			
			
			if (i == loopSize) {
				
				cout << endl;
			}
			
		}
		
		if (testWrite == 1) {
		
			cout << "Wrote 1. ExtArr is " <<  << endl; 
		}*/
		
		// cout << loopSize << " chars have passed by" << endl;
		
		
	
		
	}
	
	cArr[i] = 0;
	
	cout << '\n';
	
	cout << "\nParsing\n";
	
	char * str = cArr;
	char * pch;
	printf ("String splits at \"%s\"\n into tokens\n", str);
	pch = strtok (str, " ,\t");
	j = 0; 		// arrays start at 0
	while (pch != NULL) {
	
		// printf("%s\n", pch);
		i2dArr[j % rows][j / rows] = atoi(pch);			// parse into integer after each division
		
		// run next string token, see if it is dividable even further
		pch = strtok(NULL, " ,\t");
		
		
		
		j++;
		
		// cout << j << '\n';
	}
	
	cout << "read " <<  j << " integers" << endl;
	cout << "should be 88 integers" << endl;
	
	// test run on the matrix
	// parse as it stands in memory: 
	cout << "in matrix form: " << endl;
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++){
			
			cout << i2dArr[i][j] << "\t";
		}
		cout << endl;
	}
	
	
	
	/*while (extArr != 0) {	
		
		cout << extArr << endl;
	
	} 
	// cycleTime = millis () + 300;
	*/
	return 0;
} 
