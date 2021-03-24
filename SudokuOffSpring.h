// SudokuOffSpring.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class is in charge of mutating each sudoku square and make offspring based
// on the original sudoku 

#ifndef SUDOKUPUZZLE_SUDOKUOFFSPRING_H
#define SUDOKUPUZZLE_SUDOKUOFFSPRING_H
#include <iostream>
#include <string>
#include <vector>
#include "Puzzle.h"
#include "SudokuSquare.h"
#include "Reproduction.h"
#include <random>

using namespace std;

class SudokuOffSpring: public Reproduction {
public:

    // default constructor
    SudokuOffSpring();

    // make sudoku offspring based on the original sudoku
    // takes in a pointer to puzzle needed to get offsprings
    // Assumes puzzle is initialized and filled with values
    // returns a new puzzle that is modified a bit from the base one
    Puzzle* makeOffSpring(Puzzle *sdk);

    // whether to mutate the sudokusquare based on the mutation rate
    // takes in a sudokusquare that is considered to be mutated
    // Assumes sudokusquare has fixed and number values
    // returns a new sudokuSquare, either new or orignial
    SudokuSquare mutate(SudokuSquare square);

private:
    // to store mutation rate
    double mutation_rate;

    // for randomly pick a new value for sudoku square
    default_random_engine generator;
};

#endif //SUDOKUPUZZLE_SUDOKUOFFSPRING_H
