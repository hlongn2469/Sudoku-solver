// SudokuFactory.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class produce different puzzles based on the original input sudoku
#include <iostream>
#include <string>
#include <vector>
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include <random>

using namespace std;

class SudokuFactory: public PuzzleFactory{

public:
    //default constructor/deconstructor
    SudokuFactory();
    ~SudokuFactory();

    // create random puzzles based on the original sudoku
    // takes in a pointer to the original puzzle
    // Assumes the original puzzle is valid
    // returns new modified puzzle based on the original sudoku
    Puzzle* createPuzzle(Puzzle* base);

private:
    default_random_engine generator;
};
