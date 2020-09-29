#ifndef __RCM_H
#define __RCM_H

typedef struct Node
{
    struct Node **neighbours;

    int degree;

    int label;

    int inArray;

    int inQueue;

} Node;

typedef struct Graph
{
    Node **nodes;

    int size;
} Graph;

typedef struct Queue
{
    Node **nodes;

    int front;

    int rear;

    int capacity;

    int items;
} Queue;

typedef struct Array
{
    Node **nodes;

    int size;

    int items;
} Array;

Array *rcm(Graph *G);

Graph *initGraph(int *array, int n);

Queue *initQ(int n);
void pushQ(Queue *Q, Node *node);
Node *popQ(Queue *Q);

Array *initArr(int n);
void addToArr(Array *R, Node *node);

int compare(const void *a, const void *b);
void sortGraph(Graph *graph);

void swap(Node **a, Node **b);

Graph *finalGraph(Array *R);
int *output(Graph *graph);
void printMatrix(int *arr, int n);
void saveCsv(int *arr, int n, char *type);

int *generateInputMatrix(int n, double density);

Graph *ompInitGraph(int *array, int n);

#endif