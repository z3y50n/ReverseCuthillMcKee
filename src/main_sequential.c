#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../inc/RCM.h"

int main(int argc, char const *argv[])
{
    int n;
    double density;
    if (argc == 3)
    {
        n = atoi(argv[1]);
        density = atoi(argv[2]);
    }
    else
    {
        printf("Two arguments needed\n");
        exit(-1);
    }

    int *arr = (int *)malloc(n * n * sizeof(int));
    struct timeval start, end;

    arr = generateInputMatrix(n, density);

    Graph *graph = (Graph *)malloc(sizeof(Graph));
    Array *R = (Array *)malloc(sizeof(Array));

    gettimeofday(&start, NULL);
    graph = initGraph(arr, n);
    R = rcm(graph);
    gettimeofday(&end, NULL);

    free(arr);
    free(graph);

    double exectime = (double)((end.tv_usec - start.tv_usec) / 1.0e6 + end.tv_sec - start.tv_sec);
    printf("\t\t\tRCM Finished\n");
    printf("N: %d\nDensity: %.1lf\nSequential Execution Time: %lf\n", n, density, exectime);

    Graph *fGraph = (Graph *)malloc(sizeof(Graph));
    fGraph = finalGraph(R);
    free(R);

    int *finalArray = (int *)malloc(n * n * sizeof(int));
    finalArray = output(fGraph);
    free(fGraph);

    // printMatrix(finalArray, n);
    // saveCsv(finalArray, n, "output");

    free(finalArray);
    return 0;
}
