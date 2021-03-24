// SudokuOffSpring.cpp
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class is in charge of mutating each sudoku square and make offspring based
// on the original sudoku 

#include "SudokuOffSpring.h"
#include <random>

// default constructor
// sets mutation rate to default value
SudokuOffSpring::SudokuOffSpring(){
    mutation_rate = 0.02;
}

    // make sudoku offspring based on the original sudoku
    // takes in a pointer to puzzle needed to get offsprings
    // Assumes puzzle is initialized and filled with values
    // returns a new puzzle that is modified a bit from the base one
Puzzle* SudokuOffSpring::makeOffSpring(Puzzle *sdk){
   Sudoku *targetSDK = dynamic_cast<Sudoku*>(sdk);
    
    // create new sudoku
    Sudoku *new_sdk = new Sudoku();

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            //get temp sdk_square from mutation
            SudokuSquare temp = mutate(targetSDK->getArray(i,j));

            // set temp sdk_square to the new sudoku object
            new_sdk->setArray(temp.getVal(),temp.getFixed(),i,j);
        }
    }
    //Because you made a pointer to represent Sudoku, Sudoku object technically doesn't exist
    //As a result, you need to return the pointer that contains Sudoku, not the mem location
    return new_sdk;
}

    // whether to mutate the sudokusquare based on the mutation rate
    // takes in a sudokusquare that is considered to be mutated
    // Assumes sudokusquare has fixed and number values
    // returns a new sudokuSquare, either new or orignial
SudokuSquare SudokuOffSpring::mutate(SudokuSquare square)
{
    // if not fixed value
    if(!(square.getFixed())){
        // roll a chance/probability of mutation
        uniform_real_distribution<double> uniform_chance(0.0,1.0);
        
        // if random chance falls under mutation rate
        if(uniform_chance(generator) < mutation_rate){
            // roll a random number (1,9)
            uniform_int_distribution<int> uniform_num(1,9);

            // set square to random number
            square.setVal(uniform_num(generator));
        }
    }
    return square;
}