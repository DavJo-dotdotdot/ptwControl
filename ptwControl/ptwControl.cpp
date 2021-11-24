#include <iostream>
#include <istream>
#include <atomic>
#include <sstream>
#include <vector>
#include <chrono>
#include <numeric>
#include "ptwHeader.h"

using namespace std;
// values arrays
// external array stream
// convert external array from string to ints in main
// comparission arrays
int internalArr[] = { 0 };
// max size of array
const int totalColumns = 10;
// max amount of arrays
const int totalRows = 7;
// good arrValue
int arrVal;
// reaction threshold
float arrValThreshold = 0.7;

// values map, uses mm
// size
int boardLength = 750;
int boardWidth = 450;
int boardAngle;
// ball speed from pin to pin
int pinToPin = 10;

// life cycles
int ptwCycle;


int compMat[totalRows][totalColumns] = { 0 };
int lastPosX = 0;
int lastPosY = 0;
int currentPosX;
int currentPosY;

int boardStateArr[totalRows][totalColumns];

int lastPosArr[totalRows];
// array of stored value comparisions
int valArr[10] = { 0 };

// functions
void arrCheck(int leftArr[], int rightArr[]);
// compare matrix, uses reactToBall, all functions happen within here?
void compareVal(int externArr[]);
// react to comparisions (take in comp2darr), function of if statements regarding ball position, flipper fire/no fire/expect
int reactToBall(int finalArr[]);
// plot directions in array, waits for react
void directArr();
// 
void ballPosition();
// calculate expected direction, return vectors
// if ball heading up confirm expected direction
int ballDirection(int finalArr[]);
// calculate failure/no failure
int failToWin(int victoryState);

// remember flush at end of final checker function

ptwClass ptw;

int main() {
    
}

// checks the array 50 times per second
void arrCheck(int matArr[]) {

    for (int i = 0; i < totalRows; ++i) {
        for (int j = 0; j < totalColumns; ++j) {

            currentPosX = j;
            currentPosY = i;

            compMat[i][j] = matArr[j];

            // own function?
            // should register ball movement
          if (compMat[i][j] <= arrVal * arrValThreshold) {

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
                
                // info for other algorithms
                
            }
        }

    }

    // lifecycle check, run as own function later
    for (ptwCycle = 0; ptwCycle < 100; ptwCycle++) {
        switch (ptwCycle) {

        }
    }
}

void compareVal(int externArr[]) {
    
    // external array length
    int extArrX = sizeof(externArr) / externArr[0];
     
    for (int i = 0; i < totalRows; ++i) {
        for (int j = 0; j < totalColumns; ++j) {
            
            compMat[i][j] = externArr[j];
            
            // if matrix val is less than threshold react to ball placement
            if (compMat[i][j] <= arrVal * arrValThreshold &&
                i == totalRows) {
                // should return value to react upon, yes
                reactToBall(externArr);

            }
        }
    }

    // flush memory of matrix


}

int reactToBall(int finalArr[]) {
    
    // fire solenoid on correct side
    // pin HIGH
    // delay
    // pin LOW

}

// checks if ball is at all in matrix, called first to get "board 0"
int boardState(int externArr[]) {
   
    // 
    for (int i = 0; i < totalRows; i++) {
        for (int j = 0; j < totalColumns; j++) {

            boardStateArr[i][j] = externArr[j];



        }
    }
    
    // return 1 if board value above average
    

    // return 0 if board value below average


}