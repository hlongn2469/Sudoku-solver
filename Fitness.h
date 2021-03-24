// Fitness.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This interface calculates the sudoku's fitness number by counting duplications 

#ifndef _FN_
#define _FN_
#include <iostream>
#include <string>
#include <vector>
#include "Sudoku.h"

using namespace std;

class Fitness {

public:

    // calculate fitness of a puzzle
    // takes in a pointer to the puzzle needed fitness calculation
    // Assumes the puzzle is initialized and filled with values
    // returns int of fitness value
    virtual int howFit(Puzzle* pz) = 0;
};

#endif