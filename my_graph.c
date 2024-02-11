#include "stdio.h"
#include "my_math.h"

#ifndef SIZE
#define SIZE  10 // size of matrix board
#endif

int main()
{
    int graph[SIZE][SIZE];
    char functionToCall;

    
    scanf("%c",&functionToCall);
    while (functionToCall - 'D' != 0 || !EOF)
    {
        //switch()
        if(functionToCall - 'A' == 0){
             getData(graph);
        }

        if(functionToCall - 'B' == 0){
            int x;
            int y;
            scanf("%d %d",&x,&y);
            int ans = is_there_path(x,y,graph);
            if(ans == -1) printf("False\n");
            else printf("True\n");
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
