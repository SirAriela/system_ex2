#include "my_math.h"
#include "stdio.h"

#ifndef SIZE
#define SIZE 10 // size of matrix board
#endif
#define INF 999999

int shortest_pathhelp(int x, int y, int graph[][SIZE], int graph2[SIZE], int soFer)
{
    if (x == y)
    {
        return soFer;
    }
    graph2[x] = 1;
    int graph3[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        graph3[i] = graph2[i];
        /* code */
    }

    int i;
    int e;
    int j = INF;
    for (i = 0; i < SIZE; i++)
    {
        if (graph[x][i] > 0 && graph2[i] == 0)
        {
            e = shortest_pathhelp(i, y, graph, graph3, soFer + graph[x][i]);
            if (e < j)
            {
                j = e;
            }
        }
    }

    return j;
}

int is_there_path(int x, int y, int graph[][SIZE])
{
    if (x == y)
        return -1;
    int t = shortest_path(x, y, graph);
    if (t > -1)
    {
        return 1;
    }

    return 0;
}

int shortest_path(int x, int y, int graph[][SIZE])
{
    int graph2[SIZE] = {0};
    int t = shortest_pathhelp(x, y, graph, graph2, 0);
    if (t == INF)
    {
        return -1;
    }
    return t;
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