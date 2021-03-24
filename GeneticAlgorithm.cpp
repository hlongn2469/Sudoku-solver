// GeneticAlgorithm.cpp
// @author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// This class is in charge of solving the sudokus by using operations from other classes
// such as population, puzzle, and puzzle factory

#include "GeneticAlgorithm.h"

//Construct the algorithm with max pop_size and max_gen
//Takes in two int
GeneticAlgorithm::GeneticAlgorithm(int pop_size, int max_gen){
    population_size = pop_size;
    max_generation = max_gen;
}

//Stimulates the genetic algorithm to solve the sudoku
//Takes in nothing
//Assumes that pop_size and max_gen is initialized
//returns nothing
void GeneticAlgorithm::process(){
    factory = new SudokuFactory();
    toSolve = new Sudoku();
    cout << "Please provide us the Sudoku to solve!" << endl;
    cin >> *toSolve;

    vector<Puzzle*> firstGen;

    for(int i = 0; i < population_size; i++){
       firstGen.push_back(factory->createPuzzle(toSolve));
    }

    populationManager = new SudokuPopulation(population_size, firstGen);

    //Cull and make new generation for no more than max_generation allowed
    for(int i = 0; i < max_generation; i++)
    {
       cout << "\nGeneration: " << i + 1 << endl;
       cout << "Best puzzle for this generation:" << endl;
       cout << *populationManager->bestIndividual();
       populationManager->bestFitness();

       //If we solved it before hitting the max generation limit
       //Just stop, there's no point
       if(populationManager->bestFitness() == 0){
          break;
       }
       if(i != max_generation) {
          populationManager->cull();
          populationManager->newGeneration();
       }
    }

    //Delete the pointers to avoid leaks
    firstGen.clear();
    delete factory;
    delete toSolve;
    delete populationManager;
}