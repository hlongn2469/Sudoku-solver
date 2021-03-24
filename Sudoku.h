// Sudoku.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class represents a sudoku puzzle by storing 81 sudokusquare object in a 2D array

#include "SudokuSquare.h"
#include "Puzzle.h"
#include <vector>

using namespace std;

class Sudoku: public Puzzle{
    public:
    Sudoku();
    Sudoku(Sudoku &copy);
    ~Sudoku();

    //Prints out this Sudoku in an eye pleasing way
    //Takes in a ostream that will be used in a cout
    //Returns a ostream of the Sudoku formatted
    ostream& print(ostream& the_stream);

    //reads a long string of numbers and make a sudoku from it
    //takes in the istream to process
    //Assumes the stream is 81 char or longer
    //returns the istream
    istream& readPuzzle(istream& the_stream);

    //Set the square with its value and if it's fixed or not
    //Takes in an int of val to hold, bool if it's fixed, and 2 int of its coordinate
    //Assumes that the coordinate provided is valid
    //Returns nothing
    void setArray(int val,bool fixed, int x, int y);

    //get the square at the coordinate
    //Takes in 2 int of its coordinate
    //assumes it's a valid coordinate
    //Returns SudokuSquare at that coordinate
    SudokuSquare getArray(int x, int y);

    //Set the fitness value for this Sudoku
    //Takes in an int for the fitness val
    //Sets fitness_value of this sudoku to it
    bool setFitness(int val);

    //get the fitness value of this sudoku
    //Takes in nothing
    //returns an int of the fitness value
    int getFitness() const;

    /*
    friend bool operator<(const Sudoku &lhs, const Sudoku &rhs);
    friend bool operator>(const Sudoku &lhs, const Sudoku &rhs);
     */

    //Comparison operator overloading
    //Returns true if the left one has a lower fitness than the right
    bool lessThan(const Puzzle* rhs) const;

    //Comparison operator overloading
    //Returns true if the right one has a lower fitness than the left
    bool greaterThan(const Puzzle* rhs) const;

    private:

    // 2D array of sudokusquare object
    SudokuSquare** sdk;

    // to store fitness value of each sudoku
    int fitness_value;
};