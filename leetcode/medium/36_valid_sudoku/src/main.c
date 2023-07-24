#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    return 0;

}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){

    char*** board3d = (char***)malloc(9 * sizeof(char**));
    char** tempMatrix = (char**)malloc(3 * sizeof(char*));

    for(int quadrant = 0; quadrant < 9; quadrant++)
    {
        for(int line = 0; line < 3; line++)
        {
            char* tempArray = (char*)malloc(3 * sizeof(char));

            for(int column = 0; column < 3; column++)
            {   
                tempArray[column] = board[line+(3*quadrant/3)][column+(3 * quadrant % 3)];
            }

            tempMatrix[line] = tempArray[0];
            free(tempArray); 
        }
    }

    for(int i = 0; i < blaba; i++)
    {

    }
}
