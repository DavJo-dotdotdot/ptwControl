#pragma once
#include "ptwHeader.h"

using namespace std;

void sensorRead() {

    while (gameState == true) {
	
        serialPutchar(extArr, reqArr);
		
        while (!serialDataAvail(extArr)) {
            ;
        }
        
        i = 0;
	
        while ((cArrFeed = serialGetchar(extArr)) != '\n') {
		    cArr[i] = cArrFeed;
		    i++;
			
        }
		
        cArr[i] = 0;
	
        cout << '\n';
	
        cout << "\nParsing\n";
	
        char * str = cArr;
        char * pch;
        //printf ("String splits at \"%s\"\n into tokens\n", str);
        pch = strtok (str, " ,\t");
        j = 0; 		// arrays start at 0
            while (pch != NULL) {
	
            // printf("%s\n", pch);
            i2dArr[j % rows][j / rows] = atoi(pch);			// parse into integer after each division
		
            // run next string token, see if it is dividable even further
            pch = strtok(NULL, " ,\t");
		
            j++;
		
            }
        // test run on the matrix
        // parse as it stands in memory: 
        cout << "in matrix form: " << endl;
    
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++){
	            cout << i2dArr[i][j] << "\t";
                
                shouldFire = comparePos();
                
                if (shouldFire == true && i2dArr[i][j] < lightLevelMed * lightThreshold) {
                    fireFlipper();
                    delay(300);
                } 
                
                if (i == 0 && j == 5 && ptwCycle >= 100) {
                    lightLevelMed = setLightLevel(i2dArr[i][j]);
                    
                    cout << "\nLight level is: " << lightLevelMed << '\n';
                    
                    ptwCycle = 0;
                }
            
            }
	    cout << endl;
    
        }
        
    ++ptwCycle;
	serialFlush(extArr);
    
    }
}

//~ // called for both array sets -- use left array and right array
//~ int ptwClass::ballPosition(int extArr[], int interMat[8][11]) {

    //~ // convert ext arr to array of ints
    //~ // becomes eight sets of arrays
    //~ // need own function? c => c++, string => int, arr => matrix

    //~ for (int i = 0; i < rows; ++i) {
        //~ for (int j = 0; j < columns; ++j) {

            //~ if (interMat[i][j] <= arrVal * arrValThreshold) {

                //~ currentPosX = j;
                //~ currentPosY = i;

                //~ interMat[i][j] = extArr[j];

                //~ // ball direction
                //~ if (currentPosY < lastPosY) {
                    //~ // ball down test
                    //~ cout << "Ball down" << endl;

                //~ }
                //~ else if (currentPosY > lastPosY) {
                    //~ // Ball up test
                    //~ cout << "Ball up" << endl;

                //~ }
                
                //~ lastPosX = currentPosX;
                //~ lastPosY = currentPosY;
            //~ }
        //~ }
    //~ }

//~ }

bool ptwClass::comparePos() {
    if (i <= 3) {
        
    return false;
    } 
    
    else if (j == 0) {
        
        delay(50);
        return true;
    } 
    
    else if (j > 0) {
        return true;
    }
    
}

void ptwClass::fireFlipper() {
    //send signal to 

}

int ptwClass::setLightLevel(int extVal) {
    
    lightLevelMed = extVal;

    return lightLevelMed;
}

int ptwClass::ballDirection() {



    return 0;
}

//~ int ptwClass::failToWin(int victoryState) {



	//~ return 0;
//~ }

void ptwClass::startGame() {
       
    // hold fire on pins for five seconds while game state = false
    // pins unlock from player control and instead fires on their own two times to indicate machine play
}

bool ptwClass::gameOver() {
    
    // if receive high from arduino stop play
    
}
