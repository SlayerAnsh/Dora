# PROJECT DORA

Project Dora lets you find the people you have interacted for a definite number of past days, and hence lets you find the people who might be infected.
The project used COVID-19 as a problem statement, and tried to find the possible infected people.
The algorithm uses graphs, file handling and C++ as programming language.

The algo first picks up the file of already infected person, then tries to find out the people whom he interacted with and finally the chain continues to find each of the possibly infected poeple.

## PREREQUISITES
C++ Compiler

## HOW TO RUN DORA
First clone the project in your local machine with:
```
  git clone https://github.com/SlayerAnsh/Dora.git
```

After cloning go to ```main.cpp``` file
  
If you would like to run the file on new data set, first generate it through ```DatasetGenerator.cpp``` and then run the ```main.cpp``` file.
  
If you have your own algorithm and just want to verify it, this repo contains the file ```TestCaseSolver.cpp``` which can verify if your algorithm works correctly or not.



