# DORA
Once Again on Exploring Adventures

Dora - the explorer , as the name suggests, is an exploring algorithm. In the Project, we have designed an algorithm which helps government officers and other public officials to quickly track the number and details of the individuals needed to be quarantined as the risk of them being infected is very high.

“ It should be noted here that this algorithm on its own is not enough to do so. We can implement this algorithm in apps like AROGYA SETU which collect data of your interactions. This Algorithm then can be performed on the data. ”


## PREREQUISITES
C++ Compiler

## HOW TO RUN DORA
1) First clone the project in your local machine with:
```
  git clone https://github.com/SlayerAnsh/Dora.git
```

2) After cloning go to `main.cpp` file
  
If you would like to run the file on new data set, first generate it through `DatasetGenerator.cpp` and then run the `main.cpp` file.
  
If you have your own algorithm and just want to verify it, this repo contains the file `TestCaseSolver.cpp` which will give you solution of a particular test case which you can use to match with your solution.

## MORE ABOUT DORA
Dora is a very efficient algorithm which uses a DFS type of approach. The way it fetches data only when necessary and uses files from fetched data ( don't use unnecessary variables to store the data ) and also how it reduces the complexity of problems using sets and arrays makes it a really efficient algorithm.


**Data produced at the end of algorithm ( MAIN.cpp ) is list of all possible individuals who needs to be quarantined because they have directly ( with the infected person ) or indirectly ( with the person who was in contact with infected person directly or indirectly) possess the risk of being infected.**


