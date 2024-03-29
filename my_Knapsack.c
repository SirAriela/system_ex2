#include "stdio.h"

#define ARRAY_SIZE 5
#define MAX_WEIGHT 20

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int makeNewItems(int values[], int weights[], char items[])
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        scanf("%c ", &items[i]);
        scanf("%d ", &values[i]);
        scanf("%d ", &weights[i]);
    }
    return 0;
}

int knapSack(int weights[], int values[], int selected_bool[])
{
    int tempSIZE = ARRAY_SIZE + 1;
    int tempWeight = MAX_WEIGHT + 1;

    int profit[tempSIZE][tempWeight];
    int i, k;
    int maxprofit = 0;

    for (i = 0; i < tempSIZE; i++)
    {
        for (k = 0; k < tempWeight; k++)
        {
            profit[i][k] = 0;
        }
    }

    // dynamic table for profit
    for (i = 0; i < tempSIZE; i++)
    {
        for (k = 0; k < tempWeight; k++)
        {
            if (k == 0 || i == 0)
            {
                profit[i][k] = 0;
            }
            else if (weights[i - 1] <= k)
            {
                profit[i][k] = max(values[i - 1] + profit[i - 1][k - weights[i - 1]], profit[i - 1][k]);
            }
            else
            {
                profit[i][k] = profit[i - 1][k];
            }
        }
    }

    // back tracking
    i = tempSIZE;
    k = MAX_WEIGHT;

    while (i > 0 && k > 0)
    {
        if (profit[i][k] != profit[i - 1][k])
        {
            selected_bool[i - 1] = 1;
            k -= weights[i - 1];
        }

        i--;
    }
    for (i = 0; i < tempSIZE; i++)
    {
        for (k = 0; k < tempWeight; k++)
        {
            if (profit[i][k] > maxprofit)
                maxprofit = profit[i][k];
        }
    }

    return maxprofit;
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

    printf("Maximum profit: %d", max_profit);
    printf("\n");

    printf("Selected items:");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (selected_bool[i] == 1)
        {
            printf(" %c",items[i]);
        }
    }
    
}