#include <stdio.h>
/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.*/

int minCostClimbingStairs(int* cost, int costSize);

int main(int argc, char const *argv[])
{
    int cost[] = {0,0,1,0};
    int costSize = 4;
    int* pcost = cost;
    int a = minCostClimbingStairs(pcost, costSize);
    printf("%d", a);
}

int minCostClimbingStairs(int* cost, int costSize){
    int i = -1;
    int totalCost = 0;
    while(i < costSize)
    {
        if(i == costSize-3) //caso faltem 2
        {
            totalCost+= cost[i];
            if(cost[i+1] < cost[i+2])
            {
                i++;
                totalCost+= cost[i];
                break;
            }
            else
            {
                i+=2;
                totalCost+= cost[i];
                break;
            }
            
        }
        if(i == costSize-2 || i == costSize-1) // caso falte 1 ou 0 
        {
            totalCost+= cost[i];
            break;
        }
        if(cost[i+1] + cost[i+3] <= cost[i+2])
        {
            if(i != -1)
            { 
                totalCost += cost[i];
            }

            i++;
            totalCost+= cost[i];
            i+=2;
        }
        else
        {
            if(i != -1)
            { 
                totalCost += cost[i];
            }
            i+=2;
        }

    }
    return totalCost;
}