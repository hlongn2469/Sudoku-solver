// SudokuFitness.cpp
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class calculates the sudoku's fitness number by counting duplications 
#include "SudokuFitness.h"
#include "Puzzle.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// default constructor
SudokuFitness::SudokuFitness(){
   //Nothing to instantiate
}

// default deconstructor
SudokuFitness::~SudokuFitness(){
   //Nothing to delete
}

    // count duplicates by block order
    // takes in a pointer to the sudoku 
    // Assumes the sudoku is initialized and filled with values
    // returns int of duplication within a block
int SudokuFitness::duplicateBlock(Sudoku* sdk){
    int duplicate = 0;
    for(int i = 0; i < 9; i+=3){
        for(int j = 0; j < 9; j+=3){
            //cout << "Test count each block: " << countEachBlock(sdk,i,j,i+2,j+2) << endl;
            duplicate += countEachBlock(sdk,i,j,i+2,j+2);
            //cout << "[" << i << ", " << j << "] -> " << "[" << i+2 << ", " << j+2 << endl;
        }
    }
    return duplicate;
}


    // helper method to count each 3x3 blocks
    // takes in sudoku pointer, start coordinates and end coordinates
    // Assumes the sudoku is initialized and filled with values and coordinates are valid
    // returns int of duplicates within each 3x3 blocks
int SudokuFitness::countEachBlock(Sudoku* sdk, int start_x, int start_y, int end_x, int end_y){
    vector<int> temp;
    int duplicate = 0;
    int start_y_temp = start_y;
    // first row of block
    for(int i = 0; i < 3; i++){
        temp.push_back(sdk->getArray(start_x,start_y_temp).getVal());

        // increment to go from left to right
        start_y_temp++;
    }

    // increment and rest var to start second row of block
    start_y_temp = start_y;
    start_x++;
    for(int i = 0; i < 3; i++){
        temp.push_back(sdk->getArray(start_x,start_y_temp).getVal());
        // increment to go from left to right
        start_y_temp++;
    }

    start_y_temp = start_y;
    start_x++;
    for(int i = 0; i < 3; i++){
        temp.push_back(sdk->getArray(start_x,start_y_temp).getVal());

        // increment to go from left to right
        start_y_temp++;
    }

    for(int i = 0; i < temp.size();i++){
        for(int j = i + 1; j < temp.size(); j++){
            if(temp[i] == temp[j]){
                duplicate++;
            }
        }
    }

    temp.clear();

    return duplicate;
}

    // count duplicates by row order
    // takes in a pointer to the sudoku 
    // Assumes the sudoku is initialized and filled with values
    // returns int of duplication within a row
int SudokuFitness::duplicateRow(Sudoku* sdk){
    int duplicate = 0;

    // i loop to scan down column 
    for(int i = 0; i < 9; i++){
        
        // j loop to scan through row
        for(int j = 0; j < 9; j++){

            // k loop to compare elements
            for(int k = j + 1; k < 9; k++){
                if(sdk->getArray(i,j).getVal() == sdk->getArray(i,k).getVal()){
                    duplicate++;
                }
            }
        }
    }
    return duplicate;
}

    // count duplicates by column order
    // takes in a pointer to the sudoku 
    // Assumes the sudoku is initialized and filled with values
    // returns int of duplication within a column
int SudokuFitness::duplicateColumn(Sudoku* sdk){
    int duplicate = 0;

    // i loop to scan through row
    for(int i = 0; i < 9; i++){
        
        // j loop to scan down column
        for(int j = 0; j < 9; j++){

            // k loop to compare elements
            for(int k = j + 1; k < 9; k++){
                if(sdk->getArray(j,i).getVal() == sdk->getArray(k,i).getVal()){
                    duplicate++;
                }
            }
        }
    }
    return duplicate;
}

    // calculate fitness of a puzzle
    // takes in a pointer to the puzzle needed fitness calculation
    // Assumes the puzzle is initialized and filled with values
    // returns int of fitness value
int SudokuFitness::howFit(Puzzle* sdk){
   Sudoku *targetSDK = dynamic_cast<Sudoku*>(sdk);

   //Code below to print the results of all the other tasks for debugging purpose
    //cout << "Column: " << duplicateColumn(targetSDK) << endl;
    //cout << "Row: " << duplicateRow(targetSDK) << endl;
    //cout << "Blocks: " << duplicateBlock(targetSDK) << endl;

    int fitness = duplicateBlock(targetSDK) + duplicateColumn(targetSDK) + duplicateRow(targetSDK);
    return fitness;
}