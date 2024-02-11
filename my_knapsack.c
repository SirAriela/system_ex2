#include "stdio.h"

#define ARRAY_SIZE 5
#define MAX_WEIGHT 20

int makeNewItems(int values[], int weights[], char items[])
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        scanf(" %c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
    return 0;
}



int knapSack(int weights[], int values[], int selected_bool[])
{
    int maxValue = 0;
    int tempMax[ARRAY_SIZE] ={0};
    
    


    return maxValue;
}

int main()
{
    char items[ARRAY_SIZE];
    int values[ARRAY_SIZE];
    int weights[ARRAY_SIZE];
    int selected_bool[ARRAY_SIZE];
    int max_profit;
    int i;

    makeNewItems(values, weights, items); // gets new values and weights
    max_profit = knapSack(weights, values, selected_bool);

    printf("Maximim profit: %d", max_profit);

    printf("Selected items: ");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (selected_bool[i] == 1)
        {
            printf("%c", items[i]);
            printf(" ");
        }
    }
    printf("\b");
}