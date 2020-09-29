# Reverse Cuthill McKee Algorithm

## Implementation of the algorithm in C and optimizing it using OpenMP
***
### An assignment for course "Parallel & Distributed Systems" of AUTH
***
#### Author: Dimitrios Papageorgiou
#### Email: dim_papag@windowslive.com
#### AEM: 8884
***
**Usage**

In the main folder type:
>make sequential

or
>make parallel

Then enter:
>./bin/sequential arg1 arg2

or

>./bin/parallel arg1 arg2

for sequential and parallel version respectively

* arg1: N, The size of the Matrix (N x N) 
* arg2: Density, percentage of non-zero elements

***
Running the code in the above way will compute the RCM and print the time it took for completion

There are helper functions for visualizing the results.

* output(): will return the corresponding sparce matrix of a given graph
* printMatrix(): Is used to print a sparce matrix
* saveCSV(): Will store the results in a CSV file

You can use the above functions either in *main_sequential.c* or in *main_omp.c* depending on which version you wish to run.