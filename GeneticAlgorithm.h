// GeneticAlgorithm.h
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class is in charge of solving the sudokus by using operations from other classes
// such as population, puzzle, and puzzle factory
#include <iostream>
#include <string>
#include <vector>
#include "SudokuFactory.h"
#include "SudokuPopulation.h"
#include <random>

using namespace std;

class GeneticAlgorithm{

public:
    // parametized constructor
    // takes in poulation size and maximum generations
    // assume those values are valid
    // returns nothing
    GeneticAlgorithm(int pop_size, int max_gen);

    // process to solve the sudokus
    // takes in nothing
    // assume that maximum of generations and population size are given
    // returns nothing
    void process();
private:
    // maximum generations and population size info to process
    int population_size, max_generation;

    // pointers to other classes for operations
    Population *populationManager;
    Puzzle *toSolve;
    PuzzleFactory *factory;
};
