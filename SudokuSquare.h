// SudokuSquare.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class is storing each sudoku square value such as number and whether 
// the value is fixed

#ifndef _SQ_
#define _SQ_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SudokuSquare {

public:

    // default constructor
    SudokuSquare();

    // get the number values of sudoku square
    // takes in nothing
    // assume number has values
    // returns number values of sudokusquare
    int getVal();

    // get whether values of sudoku square is fixed or not
    // takes in nothing
    // assume is_fixed has values
    // returns is_fixed values of sudokusquare
    bool getFixed();

    // set the values of the sudokusquare
    // takes in an int value to be set
    // assume value is valid
    /// returns true if set, false otherwise
    bool setVal(int value);

    // set the fixness of the sudokusquare
    // takes in an int value to be set
    // assume value is valid
    /// returns true if set, false otherwise
    bool setFixed(bool value);

private:
    // store number value 
    int number;

    // store whether value is fixed
    bool is_fixed;
};

#endif