#include "my_math.h"
#include "stdio.h"

#ifndef SIZE
#define SIZE 10 // size of matrix board
#endif

int is_there_path(int x, int y, int graph[][SIZE])
{
    int t = shortest_path(x, y, graph);
    printf(" %d\n",t);
    return t;
}

int shortest_path(int x, int y, int graph[][SIZE])
{
    int k, i, j;
    int dist[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if(i != j){

                for (k = 0; k < SIZE; k++){
                    printf(" %d\n",dist[i][k]);
                    printf(" %d", dist[i][k] + dist[k][j]);
                    if((dist[i][k] > 0 && dist[k][j] > 0)){
                        if (dist[i][j] == 0 ||  dist[i][j] > (dist[i][k] + dist[k][j]))
                        {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                
                }
    
            }
           
        }
        
    }

    if (dist[x][y] == 0)
    {
        return -1;
    }
    return dist[x][y];
}

int getData(int graph[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf(" %d ", &graph[i][j]);
        }
    }
    return 0;
}