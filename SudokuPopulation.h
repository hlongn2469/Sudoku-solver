// SudokuPopulation.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class is in charge of storing sudoku population operations
// and create new generations of sudokus

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Population.h"
#include "SudokuOffSpring.h"
#include "SudokuFitness.h"

using namespace std;


class SudokuPopulation: public Population{
public:
    // default constructor
    SudokuPopulation();

    // default deconstructor
    ~SudokuPopulation();

    // parametized constructor
    // takes in population size and vector of puzzle pointers
    // assume pop_size and vector is holding puzzle pointers correctly
    // returns nothing
    SudokuPopulation(int pop_size, vector<Puzzle*> firstGen);

    // takes only 10% of top puzzle, get rid the rest
    // takes in nothing
    // assumes the vector of population is initialized
    // returns true if cull sucessfully, false otherwise
    bool cull();

    //Creates a new generation of population with the parents left
    //Takes in nothing
    //Assumes that the population is less than the max population size allowed
    //returns true if we made it to the end of the function 
    bool newGeneration();

    //Returns the Sudoku with the best fitness
    //Takes in nothing
    //Assumes that the population is sorted from best to worst
    //Returns the fitness score of the best Sudoku
    int bestFitness();

    //Returns the Sudoku with the best fitness score
    //Takes in nothing
    //Assumes that the population is sorted from best to worst fitness score
    //Returns Puzzle pointer of the best fitness score Sudoku
    Puzzle* bestIndividual();

    //Assign all of the Sudoku their fitness score
    //Takes in nothing
    //Assumes that the population at least has 1 member in it
    //Returns nothing
    void fitnessCheck();

    //Returns if the left has a better fitness score than the right (For std::sort)
    //Takes in 2 puzzles puzzle to compare
    //returns true if the first one has a better fitness score
    static bool betterFit(const Puzzle* left, const Puzzle* right);

private:
    // vector storing puzzle population
    vector<Puzzle*> population;

    // index of best fitness 
    int best_index;

    // set the index of the population
    // takes in an int index to be set
    // assume index is valid
    /// returns true if set, false otherwise
    bool setIndex(int index);

    // get the index best fitness puzzle in the vector
    // takes in nothing
    // assume index has values
    // returns int index
    int getIndex();
    
    // storing poulation size
    int population_size;

    // storing maximum generations
    int max_generation;

    // Pointers for operations
    Reproduction *nextGenerationMaker;
    Fitness *fitnessChecker;
};
