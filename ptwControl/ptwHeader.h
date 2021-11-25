#pragma once

#include <iostream>
#include <istream>
#include <atomic>
#include <sstream>
#include <vector>
#include <chrono>
#include <numeric>
#include <fcntl.h>
#include <errno.h>
// #include <termios.h>
// #include <unistd.h>

	class ptwClass {
	public:

		// Game states
		bool gameState;

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
		int ptwCycle;
		int lastPosX, lastPosY, currentPosX, currentPosY;

		int piMatLeft[8][11] = { 0 };  int piMatRight[8][11] = { 0 };
		
		// Sensor values
		int lightLevelMed;
		float lightThreshold = 0.7;

		// Array/matrix thresholds
		int arrVal;
		int arrValThreshold;
		
		/* ---------------------------------------------------------------------------- */

		// take from tty0, convert c to c++, string to int, int to array
		int externalRead();

		// organize response within
		int ballPosition(int extArr[], int interArr[8][11]);

		// light on sensor set, call at beginning and in ball position
		int setLightLevel(int extArr[]);

		// compare matrix, uses reactToBall, all functions happen within here?
		void compareVal();

		// react to comparisions (take in comp2darr), function of if statements regarding ball position, flipper fire/no fire/expect
		void fireFlipper();

		// Use pythagoras etc to calculate ball direction
		int ballDirection();

		// Calculate failure/no failure
		int failToWin(int victoryState);

		// If last row and last column is hit, after 1.5 seconds: 
		void gameOver();

		void startGame();
	
	};