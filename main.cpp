// main.cpp
// @Author: Kray Nguyen(1869265) and Ryan Ho (1872129)
// 3/12/2021
// Input: maximum generations and population size
// Output: solved sudoku or best unsolved sudoku with its finess score printed
// Usage: ./a.out 2 3
// then type in sequence of 81 numbers as original sudoku needed to be solved
// Assumption: only 2 parameters are passed through the command line
// Assumption: the event loop only works until the maximum generation has been reached or the sudoku is solved
// Major algorithms: Genetic algorithm that mutates each sudokusquare based on the given mutation rate
// also, this algorithm only keeps 10% of the best sudoku for each generation
#include <iostream>
#include <fstream>
#include <ostream>
#include "GeneticAlgorithm.h"

using namespace std;

int main(int argc, char *argv[]) {

   // takes in input from commandline
   int population_size = atoi(argv[1]);
   int max_generation = atoi(argv[2]);

   //create run object of genetic algorithm
   GeneticAlgorithm run(population_size, max_generation);

   // solve sudoku
   run.process();
   // Population* testPopulation = new SudokuPopulation(population_size, max_generation);
   //Puzzle *test = new Sudoku();
   // PuzzleFactory *testFactory = new SudokuFactory();
   //Fitness *testFitness = new SudokuFitness();
   // SudokuOffSpring *testReproduction = new SudokuOffSpring();
   // // Cin works with this test string
   // //123456789123456789123456789123456789123456789123456789123456789123456789123456789
   //cout << "Please give me a line for the Sudoku!" << endl;
   //cin >> *test;
   // cout << *test << endl;
   // //cout << *testFactory->createPuzzle();
   // //cout << *testFactory->createPuzzle();
   // //cout << *testFactory->createPuzzle();
   //testFitness->howFit(test);
   //cout << testFitness->howFit(test) << endl;

   // // TODO #RYAN: HELP ME DEBUG LINE32
   // // I can't cout << sudoku object (makeOffSpring returns sudoku)
   // cout << *testReproduction->makeOffSpring(test) << endl;


   // delete test;
   // delete testFactory;
   // delete testFitness;
   // delete testReproduction;
   //827154396965327148341689752593468271472513689618972435786235914154796823239841567
   //123050709020456709123050709123456789123456789123456789123456789123456789123456789
   //000000000000000000000000000000000000000000000000000000000000000000000000000000000
   //120650000938010004400089010004500089000000000290001300070140008500060427000028065

/*
   PuzzleFactory *aFactory = new SudokuFactory();
   Fitness *checkFitness = new SudokuFitness();
   Puzzle *sdk1 = new Sudoku();
   cin >> *sdk1;
   Puzzle *sdk2 = aFactory->createPuzzle(sdk1);

   sdk1->setFitness(checkFitness->howFit(sdk1));
   sdk2->setFitness(checkFitness->howFit(sdk2));

   cout << *sdk1 << endl;
   cout << *sdk2 << endl;

   cout << "fitness of sdk1: " << sdk1->getFitness() << endl;
   cout << "fitness of sdk2: " << sdk2->getFitness() << endl;
   cout << "SDK1 > SDK2 : " << (sdk1 > sdk2) << endl;
   cout << "SDK1 < SDK2 : " << (sdk1 < sdk2) << endl;
*/
   return 0;
}