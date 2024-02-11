#include "my_math.h"
#include "stdio.h"
#ifndef SIZE
#define SIZE 3 // size of matrix board
#endif
#define INFINITE 9999

int shortest_pathhelp(int x, int y, int graph[][SIZE], int graph2[SIZE], int soFer);

int is_there_path(int x, int y, int graph[][SIZE])
{
    int t = shortest_path(x, y, graph);
    if (x == y)
        return 0;

    if (t != -1)
    {
        return 1;
    }

    return 0;
}

int shortest_path(int x, int y, int graph[][SIZE])
{
    int graph2[SIZE] = {0};
    int t = shortest_pathhelp(x, y, graph, graph2, 0);
    if (t == INFINITE)
    {
        return -1;
    }
    return t;
}

int shortest_pathhelp(int x, int y, int graph[][SIZE], int graph2[SIZE], int soFer)
{
    if (x == y)
    {
        return soFer;
    }

    graph2[x] = 1;

    int i;
    int e;
    int j = INFINITE;
    for (i = 0; i < SIZE; i++)
    {
        if (graph[x][i] == 1 && graph2[i] == 0)
        {
            e = shortest_pathhelp(i, y, graph, graph2, soFer + 1);
            if ((e) < j)
            {
                j = e;
            }
        }
    }
    return j;
}

int getData(int graph[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    return 0;
}