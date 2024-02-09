#include "my_math.h"
#ifndef SIZE
#define SIZE 10 // size of matrix board
#endif

#define NO_PATH -1
#define INF 99999 // Just an example, use an appropriate value based on your application

int shortest_pathhelp(int x, int y, int graph[][SIZE], int graph2[SIZE], int soFer)
{
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
    {
        return NO_PATH; // Input coordinates out of range
    }

    if (x == y)
    {
        return soFer;
    }
    graph2[x] = 1;
    int i;
    int e;
    int j = INF; // Initialize with a large value
    for (i = 0; i < SIZE; i++)
    {
        if (graph[x][i] == 1 && graph2[i] == 0)
        {
            e = shortest_pathhelp(i, y, graph, graph2, soFer + 1);
            if (e != NO_PATH && e < j)
            {
                j = e;
            }
        }
    }

    return (j == INF) ? NO_PATH : j; // Return NO_PATH if no valid path found
}

int shortest_path(int x, int y, int graph[][SIZE])
{
    int graph2[SIZE] = {0};
    int t = shortest_pathhelp(x, y, graph, graph2, 0);
    return t;
}

int is_there_path(int x, int y, int graph[][SIZE])
{
    int t = shortest_path(x, y, graph);
    return (t != NO_PATH);
}
