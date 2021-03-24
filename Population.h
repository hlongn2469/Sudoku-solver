// Population.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This interface is in charge of storing sudoku population operations
// and create new generations of sudokus

#ifndef _PP_
#define _PP_
#include <iostream>
#include <string>
#include <vector>
#include "Fitness.h"

using namespace std;

class Population {

public:
    // default deconsturctor
    virtual ~Population(){};

    // takes only 10% of top puzzle, get rid the rest
    // takes in nothing
    // assumes the vector of population is initialized
    // returns true if cull sucessfully, false otherwise
    virtual bool cull() = 0;

    //Creates a new generation of population with the parents left
    //Takes in nothing
    //Assumes that the population is less than the max population size allowed
    //returns true if we made it to the end of the function
    virtual bool newGeneration() = 0;

    //Returns the Sudoku with the best fitness
    //Takes in nothing
    //Assumes that the population is sorted from best to worst
    //Returns the fitness score of the best Sudoku
    virtual int bestFitness() = 0;

    //Returns the Sudoku with the best fitness score
    //Takes in nothing
    //Assumes that the population is sorted from best to worst fitness score
    //Returns Puzzle pointer of the best fitness score Sudoku
    virtual Puzzle* bestIndividual() = 0;
};

#endif