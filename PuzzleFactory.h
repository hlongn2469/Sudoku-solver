// PuzzleFactory.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This interface produce different puzzles based on the original input sudoku

#ifndef _PF_
#define _PF_
#include <iostream>
#include <string>
#include <vector>
#include "Puzzle.h"

using namespace std;

class PuzzleFactory {

public:
    // default deconstructor
    virtual ~PuzzleFactory(){};
    
    // create random puzzles based on the original sudoku
    // takes in a pointer to the original puzzle
    // Assumes the original puzzle is valid
    // returns new modified puzzle based on the original sudoku
    virtual Puzzle* createPuzzle(Puzzle* base) = 0;

private:
    
};

#endif