// SudokuSquare.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class is storing each sudoku square value such as number and whether 
// the value is fixed
#include "SudokuSquare.h"

// default constructor
// set number to 0 and square is not fixed
SudokuSquare::SudokuSquare(){
    number = 0;
    is_fixed = false;
}

    // get whether values of sudoku square is fixed or not
    // takes in nothing
    // assume is_fixed has values
    // returns is_fixed values of sudokusquare
bool SudokuSquare::getFixed(){
    return is_fixed;
}

    // get the number values of sudoku square
    // takes in nothing
    // assume number has values
    // returns number values of sudokusquare
int SudokuSquare::getVal()
{
    return number;
}

    // set the fixness of the sudokusquare
    // takes in an int value to be set
    // assume value is valid
    /// returns true if set, false otherwise
bool SudokuSquare::setFixed(bool fix){
    is_fixed = fix;
    return true;
}

    // set the values of the sudokusquare
    // takes in an int value to be set
    // assume value is valid
    /// returns true if set, false otherwise
bool SudokuSquare::setVal(int value)
{
    number = value;
    return true;
}
