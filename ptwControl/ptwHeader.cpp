#pragma once
#include "ptwHeader.h"

using namespace std;

// called for both array sets -- use left array and right array
int ptwClass::ballPosition(int extArr[], int interMat[][10]) {

    // convert ext arr to array of ints
    // becomes eight sets of arrays
    // need own function? c => c++, string => int, arr => matrix

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {

            if (interMat[i][j] <= arrVal * arrValThreshold) {

                currentPosX = j;
                currentPosY = i;

                interMat[i][j] = extArr[j];

                // ball direction
                if (currentPosY < lastPosY) {
                    // ball down test
                    cout << "Ball down" << endl;

                }
                else if (currentPosY > lastPosY) {
                    // Ball up test
                    cout << "Ball up" << endl;

                }
                
                lastPosX = currentPosX;
                lastPosY = currentPosY;
            }
        }
    }

}

void ptwClass::compareVal() {


}

void ptwClass::fireFlipper() {
    //send signal to 

}

int ptwClass::setLightLevel(int extArr[]) {
    
    for (int i = 0; i < columns/2; ++i) {
        if (i == columns / 2) {

            lightLevelMed = extArr[i];
        }
    }

    return lightLevelMed;
}

int ptwClass::ballDirection() {



    return 0;
}

// 
int ptwClass::failToWin(int victoryState) {



	return 0;
}

void ptwClass::startGame() {
       
    // hold fire on pins for five seconds while game state = false
    // pins unlock from player control and instead fires on their own two times to indicate machine play
}

void ptwClass::gameOver() {

    // if start sensor is covered for 3 seconds =>
    // game state = false
}
