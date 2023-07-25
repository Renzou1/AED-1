bool rowCheck(char** board, int row);
bool columnCheck(char** board, int column);
bool quadrantCheck(char** board, int _row, int _column);


bool isValidSudoku(char** board, int boardSize, int* boardColSize){

    for(int i = 0; i < 9; i++)
    {
        if(!rowCheck(board, i)) return false;
        if(!columnCheck(board, i)) return false;
    }

    for(int _row = 0; _row <= 6; _row+= 3)
    {
        for(int _column = 0; _column <= 6; _column+= 3)
        {
            if(!quadrantCheck(board, _row, _column)) return false;
        }
    }

    return true;

}

bool rowCheck(char** board, int row)
{
    int count[9] = {0};

    for(int column = 0; column < 9; column++)
        {
            if(board[row][column] >= '1' && board[row][column] <= '9')
            {
                count[board[row][column] - '1']++;  
            }
        }

    for(int i = 0; i < 9; i++)
    {
        if (count[i] != 0 && count[i] != 1)
        {
            return false;
        }
    }
    return true;

}

bool columnCheck(char** board, int column)
{
    int count[9] = {0};

    for(int row = 0; row < 9; row++)
        {
            if(board[row][column] >= '1' && board[row][column] <= '9')
            {
                count[board[row][column] - '1']++;
            }
        }
    
    for(int i = 0; i < 9; i++)
    {
        if(count[i] != 0 && count[i] != 1)
        {
            return false;
        }
    }
    return true;
    
}

bool quadrantCheck(char** board, int _row, int _column)
{
    int count[9] = {0};

    for(int row = _row; row < _row + 3; row++)
    {
        for(int column = _column; column < _column + 3; column++)
        {
            if(board[row][column] >= '1' && board[row][column] <= '9')
                {
                    count[board[row][column] - '1']++;
                }
        }
    } 

    for(int i = 0; i < 9; i++)
    {
        if(count[i] != 0 && count[i] != 1)
        {
            return false;
        }
    } 
    return true;

}