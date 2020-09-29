#include <stdio.h>
#include <stdlib.h>

#include "../inc/RCM.h"

Array *rcm(Graph *G)
{
    Array *R = (Array *)malloc(sizeof(Array));
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    R = initArr(G->size);
    Q = initQ(G->size);

    Node *node = (Node *)malloc(sizeof(Node));

    int graph_count = 0;

    while (R->items < R->size)
    {
        if (!Q->items)
        {
            node = G->nodes[graph_count];
            graph_count++;
        }
        else
        {
            node = popQ(Q);
        }

        if (!node->inArray)
        {
            addToArr(R, node);
            for (int i = 0; i < node->degree; i++)
            {
                if (!node->neighbours[i]->inQueue && !node->neighbours[i]->inArray)
                {
                    pushQ(Q, node->neighbours[i]);
                }
            }
        }
    }
    for (int i = 0; i < R->size / 2; i++)
    {
        swap(&(R->nodes[i]), &(R->nodes[R->size - i - 1]));
    }

    return R;
}
