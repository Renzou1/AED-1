/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 //tentar usar debugger pra ver oq faltou, apenas
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){

    int returnArray[intervalsSize][2];
    int size = 0;
    int temp[2];

    for(int j = 0; j < intervalsSize - 1; j++)
    {
        for(int i = j; i < intervalsSize - 1; i++)
        {
            temp[0] = intervals[j][0];
            temp[1] = intervals[j][1];
            if(temp[0] == -1) continue;
            if(intervals[i+1][0] == -1) continue;
            if(intervals[i+1][1] == -1) continue;
            //expand upper range case
            if(intervals[i + 1][0] >= temp[0] 
            && intervals[i+1][0] <= temp[1]
            && intervals[i+1][1] > temp[1])
            {
                temp[1] = intervals[i+1][1];
                intervals[i+1][0] = -1;
                intervals[i+1][1] = -1;

                //extend lower range
            }  else if(intervals[i+1][1] >= temp[0]
            && intervals[i+1][1] <= temp[1]
            && intervals[i+1][0] < temp[0])
            {
                temp[0] = intervals[i+1][0];
                intervals[i+1][0] = -1;
                intervals[i+1][1] = -1;
            }
        }
        returnArray[size][0] = temp[0];
        returnArray[size][1] = temp[1];
        size++;
    }

    int** trueReturn = (int**)malloc(sizeof(int*) * size);
    int* columnSizes = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
    {
        columnSizes[i] = 2;
        //returnColumnSizes[0] = 2;
        trueReturn[i] = (int*)malloc(sizeof(int) * 2);
        trueReturn[i][0] = returnArray[i][0];
        trueReturn[i][1] = returnArray[i][1];
    }
    *returnColumnSizes = &columnSizes[0];
    *returnSize = size;
    return trueReturn;
}
