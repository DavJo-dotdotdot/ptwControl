#pragma once

#include <iostream>
#include <istream>
#include <atomic>
#include <sstream>
#include <chrono>
#include <numeric>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringSerial.h>

	class ptwClass {
	public:

		// Game states
		bool gameState;
		bool shouldFire;
		
		// Array count in, have to be i and j for convinience for now
		int i = 0;
		int j = 0;
		
		
		// Table dimensions
		float tableLength = 750.0; float tableWidth = 450.0; float pinDistance = 10.0;
		float tableAngle;

		// Array dimensions
		const int columns = 10;
		const int rows = 7;

		// Ball attributes
		float ballSpeed; float warnSpeed = 5.0;
		float ballWeight;

		// Array/matrix attributes
		int ptwCycle = 100;
		int lastPosX, lastPosY, currentPosX, currentPosY;

		int piMatLeft[8][11] = { 0 };  int piMatRight[8][11] = { 0 };
		
		// Sensor values
		int lightLevelMed = 255; 	// will make it fire on startup
		float lightThreshold = 0.7;

		// Array/matrix thresholds
		int arrVal;
		int arrValThreshold;
		
		/* ---------------------------------------------------------------------------- */

		// take from tty0, convert c to c++, string to int, int to array
		void sensorRead();

		// organize response within
		int ballPosition(int extArr[], int interArr[8][11]);

		// light on sensor set, call at beginning and in ball position
		int setLightLevel(int extVal);

		// compare matrix, uses reactToBall, all functions happen within here?
		bool comparePos();

		// react to comparisions (take in comp2darr), function of if statements regarding ball position, flipper fire/no fire/expect
		void fireFlipper();

		// Use pythagoras etc to calculate ball direction
		int ballDirection();

		// Calculate failure/no failure
		int failToWin(int victoryState);

	};
