// Reproduction.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This interface is in charge of mutating each sudoku square and make offspring based
// on the original sudoku 
#ifndef _RP_
#define _RP_
#include <iostream>
#include <string>
#include <vector>
#include "Fitness.h"
#include "SudokuSquare.h"

using namespace std;

class Reproduction {

public:

    //Reproduction();

    // make sudoku offspring based on the original sudoku
    // takes in a pointer to puzzle needed to get offsprings
    // Assumes puzzle is initialized and filled with values
    // returns a new puzzle that is modified a bit from the base one
    virtual Puzzle* makeOffSpring(Puzzle *pz) = 0;

    // whether to mutate the sudokusquare based on the mutation rate
    // takes in a sudokusquare that is considered to be mutated
    // Assumes sudokusquare has fixed and number values
    // returns a new sudokuSquare, either new or orignial
    virtual SudokuSquare mutate(SudokuSquare square) = 0;

private:
};

#endif