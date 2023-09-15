#include <stdio.h>
#include <stdlib.h>
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 //tentar usar debugger pra ver oq faltou, apenas

int main()
{
    int intervalsSize = 4;
    int** intervals = (int**)malloc(intervalsSize * sizeof(int*));
    for(int i = 0; i < intervalsSize; i++)
    {
        intervals[i] = (int*)malloc(2 * sizeof(int));
    }
    intervals[0][0] = 1;
    intervals[0][1] = 3;

    intervals[1][0] = 2;
    intervals[1][1] = 6;

    intervals[2][0] = 8;
    intervals[2][1] = 10;

    intervals[3][0] = 15;
    intervals[3][1] = 18;

    int returnSize;
    int intervalsColSize = 2;
    int* returnColumnSizes;

    int** returnArray = merge(intervals, intervalsSize, &intervalsColSize, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; i++)
    {
        for(int j = 0; j < returnColumnSizes[i]; j++)
        {
        printf("%d ", returnArray[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < intervalsSize; i++)
        free(intervals[i]);
    free(intervals);
    free(returnColumnSizes);
    for(int i = 0; i < returnSize; i++)
        free(returnArray[i]);
    free(returnArray);
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){

    int size = 0;
    int temp[2];
    int j;
    int key;
    int key2;

    int** returnArray = (int**)malloc(intervalsSize *sizeof(int*));

    //modified insertion sort
    for(int i = 1; i < intervalsSize; i++)
    {
        j = i - 1;
        key = intervals[i][0];
        key2 = intervals[i][1];

        while(j >= 0 && intervals[j][0] > key)
        {
            intervals[j + 1][0] = intervals[j][0];
            intervals[j + 1][1] = intervals[j][1];
            j = j - 1;
        }
        intervals[j + 1][0] = key;
        intervals[j + 1][1] = key2;
    }

    for(int j = 0; j < intervalsSize; j++)
    {
        temp[0] = intervals[j][0];
        temp[1] = intervals[j][1];      

        for(int i = j; i < intervalsSize; i++)
        {
            if(temp[0] == -1) break;
            if(intervals[i][0] == -1) continue;
            if(intervals[i][1] == -1) continue;

            //expand upper range case
            if(intervals[i][0] >= temp[0] 
            && intervals[i][0] <= temp[1]
            && intervals[i][1] >= temp[1])
            {
                temp[1] = intervals[i][1];
                intervals[i][0] = -1;
                intervals[i][1] = -1;
            }
            //extend lower range
            if(intervals[i][1] >= temp[0]
            && intervals[i][1] <= temp[1]
            && intervals[i][0] <= temp[0])
            {
                temp[0] = intervals[i][0];
                intervals[i][0] = -1;
                intervals[i][1] = -1;
            }
            //absorb
            if(intervals[i][0] >= temp[0]
            && intervals[i][1] <= temp[1])
            {
                intervals[i][0] = -1;
                intervals[i][1] = -1;
            }
        }
        if(temp[0] != -1)
        {
        returnArray[size] = (int*)malloc(2 * sizeof(int));    
        returnArray[size][0] = temp[0];
        returnArray[size][1] = temp[1];
        size++;
        }
    }


    int* columnSizes = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++)
    {
        columnSizes[i] = 2;
    }
    *returnColumnSizes = &columnSizes[0];
    *returnSize = size;

    return returnArray;
}
