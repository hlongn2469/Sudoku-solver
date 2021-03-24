// Sudoku.cpp
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class represents a sudoku puzzle by storing 81 sudokusquare object in a 2D array

#include <iostream>
#include "Sudoku.h"
#include <string>

using namespace std;

//Default constructor
Sudoku::Sudoku(){
   sdk = new SudokuSquare*[9];
    for(int i = 0; i < 9; i++){
       sdk[i] = new SudokuSquare[9];
    }
    fitness_value = 0;
}

//Copy constructor
Sudoku::Sudoku(Sudoku &copy){
    sdk = new SudokuSquare*[9];
    for(int i = 0; i < 9; i++){
       sdk[i] = new SudokuSquare[9];
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            sdk[i][j].setVal(copy.getArray(i,j).getVal());
            if(sdk[i][j].getFixed())
            {
               sdk[i][j].setFixed(true);
            }
        }
    }
}

//Default destructor
Sudoku::~Sudoku(){
   //Deletes all the pointers in the array to avoid leaks
   for(int i = 0; i < 9; i++)
   {
      delete[] sdk[i];
      sdk[i] = nullptr;
   }
   delete[] sdk;
   sdk = nullptr;
}

//Set the square with its value and if it's fixed or not
//Takes in an int of val to hold, bool if it's fixed, and 2 int of its coordinate
//Assumes that the coordinate provided is valid
//Returns nothing
void Sudoku::setArray(int val, bool fixed, int x, int y){
    sdk[x][y].setVal(val);
    sdk[x][y].setFixed(fixed);
}

//get the square at the coordinate
//Takes in 2 int of its coordinate
//assumes it's a valid coordinate
//Returns SudokuSquare at that coordinate
SudokuSquare Sudoku::getArray(int x, int y){
    return sdk[x][y];
}

//Set the fitness value for this Sudoku
//Takes in an int for the fitness val
//Sets fitness_value of this sudoku to it
bool Sudoku::setFitness(int val){
    fitness_value = val;
    return true;
}

//get the fitness value of this sudoku
//Takes in nothing
//returns an int of the fitness value
int Sudoku::getFitness() const{
    return fitness_value;
}

//Prints out this Sudoku in an eye pleasing way
//Takes in a ostream that will be used in a cout
//Returns a ostream of the Sudoku formatted
ostream& Sudoku::print(ostream& the_stream) {
    for(int i = 0; i < 9; i++){
        if(i % 3 == 0){
            the_stream << "+-------+-------+-------+" << endl;
        }
         the_stream << "| ";

        for(int j = 0; j < 9; j++){
            the_stream << sdk[i][j].getVal() << " ";
            if((j + 1) % 3 == 0){
               the_stream << "| "; 
            }
        }
      the_stream << endl;
    }
    the_stream << "+-------+-------+-------+" << endl;

    the_stream << "Fitness value: " << fitness_value << endl;
    return the_stream;
}

//reads a long string of numbers and make a sudoku from it
//takes in the istream to process
//Assumes the stream is 81 char or longer
//returns the istream
istream& Sudoku::readPuzzle(istream &the_stream) {
   char toProcess;
   int pos = 0;
   //Nested loops to go through the squares one by one, in row major order
   for(int i = 0; i < 9; i++)
   {
      for(int j = 0; j < 9; j++)
      {
         the_stream.get(toProcess);
         //Only attempt to add the next char if it's actually a digit
         if(isdigit(toProcess))
         {
            sdk[i][j].setVal(toProcess - '0');
            if(sdk[i][j].getVal() != 0)
            {
               sdk[i][j].setFixed(true);
            }
         }
         //In the case if it's not a digit, we still haven't filled out this square yet
         //Thus we need to try again
         else
         {
            j--;
         }
         pos++;
      }
   }
   return the_stream;
}

//Comparison operator overloading
//Returns true if the left one has a lower fitness than the right
bool Sudoku::lessThan(const Puzzle *rhs) const{
   return fitness_value < rhs->getFitness();
}

//Comparison operator overloading
//Returns true if the right one has a lower fitness than the left
bool Sudoku::greaterThan(const Puzzle *rhs) const{
   return fitness_value > rhs->getFitness();
}