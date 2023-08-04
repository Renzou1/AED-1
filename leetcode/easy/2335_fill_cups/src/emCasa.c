// if its possible to fill 2 cups, then fill 2 cups
#include <stdio.h>

#define SIZE 3

int fillCups(int* amount, int amountSize);

int main()
{
    int amount[SIZE] = {5,4,4};
    int amountSize = SIZE;
    int x = fillCups(amount, amountSize);
    printf("%d", x);

}

// if its possible to fill 2 cups, then fill 2 cups
int fillCups(int* amount, int amountSize){

    int seconds = 0;
    int biggest = 0;
    int secondBiggest = 0;
    int flag = 100;

    for(int i = 0; flag != 0; i++)
    {
        for(int c = 0; c < amountSize; c++) // finds first to decrement
        {
            if(amount[c] > amount[biggest])
            {
                biggest = c;
            }
        }
        flag = amount[biggest];

        if(biggest == 0) secondBiggest = 1;

        for(int j = 0; j < amountSize; j++) // finds second to decrement
        {
            if(amount[j] > amount[secondBiggest] && j != biggest)
            {
                secondBiggest = j;
            }
        }
        if(amount[secondBiggest] == 0)
        {
            while(amount[biggest] > 0)
            {
                amount[biggest]--;
                seconds++;
            }
            return seconds;
        }
        amount[biggest]--;
        amount[secondBiggest]--;
        seconds++;
        biggest = 0;
        secondBiggest = 0;
    }
    return seconds;
}   
