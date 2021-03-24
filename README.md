# Sudoku-solver

# Statement of work:

Design and implement a set of classes that define the abstractions necessary to solve puzzles of any kind using a Genetic Algorithm. Then, produce concrete subclasses that implement these interfaces for sudoku. The overall class relationships are described by the UML figure below:

![prog4-UML](https://user-images.githubusercontent.com/78957509/112391202-ca3e1400-8cb4-11eb-95c2-9fe7dd250d7a.jpg)

# Flow of control

The program should take two command line arguments: the size of the population and the maximum number of generations. It should then read the sudoku puzzle from cin and generate the first generation (i.e., randomly fill in the squares that are not fixed to produce a population of the specified size with that many different Puzzles). It should then begin the GA iterations. In each iteration, it should:
1. ask the Population for the bestFitness, halting iterations if a solution has been found or if the maximum number of generations limit has been reached
2. command the Population to cull 90\% of its Puzzles
3. command the Population to reproduce a newGeneration.

At the end, The program output the best puzzle found, with its fitness value.

Design doc: [Program4 design (1).pdf](https://github.com/hlongn2469/Sudoku-solver/files/6200815/Program4.design.1.pdf)
