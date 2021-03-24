// SudokuFitness.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class calculates the sudoku's fitness number by counting duplications 

#include "Fitness.h"
#include "Puzzle.h"

using namespace std;

class SudokuFitness: public Fitness {
    public:

    // default constructors/deconstructors
    SudokuFitness();
    ~SudokuFitness();  

    // calculate fitness of a puzzle
    // takes in a pointer to the puzzle needed fitness calculation
    // Assumes the puzzle is initialized and filled with values
    // returns int of fitness value
    int howFit(Puzzle* sdk);

    // count duplicates by row order
    // takes in a pointer to the sudoku 
    // Assumes the sudoku is initialized and filled with values
    // returns int of duplication within a row
    int duplicateRow(Sudoku* sdk);

    // count duplicates by block order
    // takes in a pointer to the sudoku 
    // Assumes the sudoku is initialized and filled with values
    // returns int of duplication within a block
    int duplicateBlock(Sudoku* sdk);

    // count duplicates by column order
    // takes in a pointer to the sudoku 
    // Assumes the sudoku is initialized and filled with values
    // returns int of duplication within a column
    int duplicateColumn(Sudoku* sdk);

    private:

    // helper method to count each 3x3 blocks
    // takes in sudoku pointer, start coordinates and end coordinates
    // Assumes the sudoku is initialized and filled with values and coordinates are valid
    // returns int of duplicates within each 3x3 blocks
    int countEachBlock(Sudoku* sdk, int start_x, int start_y, int end_x, int end_y);
};