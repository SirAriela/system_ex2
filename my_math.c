#include "my_math.h"
#ifndef SIZE
#define SIZE 10 // size of matrix board
#endif

int shortest_pathhelp(int x, int y, int graph[][SIZE], int graph2[SIZE], int soFer)
{
    if (x == y)
    {
        return soFer;
    }
    graph2[x] = 1;
    int i;
    int e;
    int j = 50;
    for (i = 0; i < SIZE; i++)
    {
        if (graph[x][i] == 1 && graph2[i] == 0)
        {
            e = shortest_pathhelp(i, y, graph, graph2, soFer + 1 < j);
            if (e)
            {
                j = e;
            }
        }
    }

    return j;
}


int shortest_path(int x, int y, int graph[][SIZE])
{
    int graph2[SIZE] = {0};
    int t = shortest_pathhelp(x, y, graph, graph2, 0);
    if (t == 50)
    {
        return -1;
    }
    return t;
}

int is_there_path(int x, int y, int graph[][SIZE])
{
    int t = shortest_path(x, y, graph);
    if (t > -1)
    {
        return 1;
    }

    return 0;
}




