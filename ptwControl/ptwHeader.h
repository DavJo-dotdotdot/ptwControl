#pragma once

	class ptwClass {
	public:

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
		int ptwInternMat[7][10] = { 0 };

		// organize response within
		int ballPosition(int arr[]);

		// compare matrix, uses reactToBall, all functions happen within here?
		void compareVal();

		// react to comparisions (take in comp2darr), function of if statements regarding ball position, flipper fire/no fire/expect
		void fireFlipper();

		// Use pythagoras etc to calculate ball direction
		int ballDirection();

		// Calculate failure/no failure
		int failToWin(int victoryState);
	};