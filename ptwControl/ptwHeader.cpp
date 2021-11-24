#include "ptwHeader.h"

ptwClass ptw;


// called for both array sets -- use left array and right array
int ptwClass::ballPosition(int arr[]) {

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {

			currentPosY = i;
			currentPosX = j;

			if (currentPosY == rows) {

			}

		}
	}

}

// 
void ptwClass::fireFlipper() {
	// send signal to flipper for ball within array fire 

	// if here could use changes on bottom array for when to fire


}

// 
int ptwClass::failToWin(int victoryState) {
	

	return 0;
}

