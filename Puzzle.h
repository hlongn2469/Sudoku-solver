// Puzzle.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class represents a sudoku interface by storing 81 sudokusquare object in a 2D aray

#ifndef _PZ_
#define _PZ_
#include <iostream>
#include <string>
#include <vector>
#include "SudokuSquare.h"

using namespace std;

class Puzzle {
   
public:
   // default constructors
   Puzzle(){};
   virtual ~Puzzle(){};

   // necessary operator overloads
    friend ostream& operator<<(ostream & the_stream, Puzzle& rhs)
    {
       rhs.print(the_stream);
       return the_stream;
    }

    friend istream& operator>>(istream & the_stream, Puzzle& rhs)
    {
       rhs.readPuzzle(the_stream);
       return the_stream;
    }

    bool operator<(const Puzzle* rhs)
    {
       return lessThan(rhs);
    }

    bool operator>(const Puzzle* rhs)
    {
       return greaterThan(rhs);
    }

   //get the fitness value of this sudoku
   //Takes in nothing
   //returns an int of the fitness value
   virtual int getFitness() const = 0;

   //Set the fitness value for this Sudoku
   //Takes in an int for the fitness val
   //Sets fitness_value of this sudoku to it
   virtual bool setFitness(int val) =0;

   //Comparison operator overloading
   //Returns true if the left one has a lower fitness than the right
   virtual bool lessThan(const Puzzle* rhs)const=0;

   //Comparison operator overloading
   //Returns true if the right one has a lower fitness than the left
   virtual bool greaterThan(const Puzzle* rhs)const=0;
private:
    
    //Prints out this Sudoku in an eye pleasing way
    //Takes in a ostream that will be used in a cout
    //Returns a ostream of the Sudoku formatted
    virtual ostream& print(ostream& the_stream) = 0;

    //reads a long string of numbers and make a sudoku from it
    //takes in the istream to process
    //Assumes the stream is 81 char or longer
    //returns the istream
    virtual istream& readPuzzle(istream& the_stream) = 0;
};

#endif