#include "stdio.h"
#include "my_math.h"

#ifndef SIZE
#define SIZE  3 // size of matrix board
#endif

int main()
{
    int graph[SIZE][SIZE];
    char functionToCall;

    
    scanf("%c",&functionToCall);
    while (functionToCall - 'D' != 0 || !EOF)
    {
        if(functionToCall - 'A' == 0){
             for (int i = 0; i < SIZE; i++) 
             {
                for (int j = 0; j < SIZE; j++) 
                {
                    scanf("%d", &graph[i][j]);
                }
             }
        }

        if(functionToCall - 'B' == 0){
            int x;
            int y;
            scanf("%d %d",&x,&y);
            int ans = is_there_path(x,y,graph);
            printf("%s\n", ans ? "True" : "False");
        }

        if(functionToCall - 'C' == 0)
        {
            int x;
            int y;
            scanf("%d %d",&x,&y);
            int ans = shortest_path(x,y,graph);
            printf("%d\n", ans);
        }
        
        scanf("%c",&functionToCall);

    }


    return 0;
    
}
