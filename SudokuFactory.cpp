// SudokuFactory.cpp
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class produce different puzzles based on the original input sudoku
#include "SudokuFactory.h"
#include "Sudoku.h"
#include <random>

// default constructor
SudokuFactory::SudokuFactory(){
    
}

// default destructor
SudokuFactory::~SudokuFactory(){

}

   // create random puzzles based on the original sudoku
   // takes in a pointer to the original puzzle
   // Assumes the original puzzle is valid
   // returns new modified puzzle based on the original sudoku
Puzzle* SudokuFactory::createPuzzle(Puzzle* base){
   Sudoku *tempSudoku = dynamic_cast<Sudoku *>(base);
   Sudoku *newSudoku = new Sudoku;
   uniform_int_distribution<int> uniform(1,9);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
           // if the sudokusquare is not fixed
           if(!tempSudoku->getArray(i,j).getFixed())
           {
              //modify the square values
              newSudoku->setArray(uniform(generator),false, i, j);
           }
            // else, remain original value
           else
           {
              newSudoku->setArray(tempSudoku->getArray(i,j).getVal(), true, i, j);
           }
        }
    }

    Puzzle* tempReturn = newSudoku;
    return tempReturn;
    //Don't forget to delete the pointer after dealing with it outside of the function!
}