int min(int x, int y)
{
    if(x < y) return x;
    return y;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){

    int start = 0;
    int end = matrixSize - 1;
    int mid = end/2;
    int col = -1;

    while(start <= end)
    {
        mid = start + (end-start)/2;
        if(matrix[mid][0] <= target)
        {
            start = mid + 1;
        }
        else if(matrix[mid][0] > target)
        {
            end = mid - 1;
        }
    }

    col = min(start, end);
    if(col < 0) col = 0;
    if(col > matrixSize - 1) col = matrixSize - 1;

    int i = 0;
    start = 0;
    end = matrixColSize[col] - 1;
    while(start <= end)
    {
        mid = start + (end-start)/2;

        if(matrix[col][mid] < target)
        {
            start = mid + 1;
        }
        else if(matrix[col][mid] > target)
        {
            end = mid - 1;
        }
        if(matrix[col][mid] == target)
        {
            return true;
        }
    }

    return false;
}
