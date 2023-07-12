#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int NumberOfDigits(int x);
int currentDigit(int digits, int x);

const TAMANHO = 100;

int main()
{
    int x = 5;
    bool k = isPalindrome(x);
}


bool isPalindrome(int x){
    int Digitos[Tamanho];
    int NumberOfX = NumberOfDigits(x);

    for(int i = 0; NumberOfX != 0;i++)
    {
        NumberOfX = NumberOfX - i;
        Digitos[i] = currentDigit(NumberOfX, x);
        x = x - (currentDigit(NumberOfX, x) * pow(10, NumberOfX - i - 1 ));
    }
    if(x > 0)
    {
        return false;
    }
    else{
        return true;
    }
}

int NumberOfDigits(int x)
{
    int digits = 1;

    for(long i = 10; i < x; i*10)
    {
        digits++;
    }
    return digits;
}

int currentDigit(int digits, int x)
{
    int currentDigit = 0;

    for(int c = 0; c < 10; c++)
    {
        if(x - pow(10,(double) digits-1) < 0)
        {
            currentDigit++; 
        } else{
            break;
        }
    }
}