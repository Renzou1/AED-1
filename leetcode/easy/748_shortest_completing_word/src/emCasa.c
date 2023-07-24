#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize);

int main(){

    char licensePlate[] = "1s3 PSt";
    char ** words = (char **)malloc(sizeof(char *) * 4);
    const int wordsSize = 4;
    char* ptr1 = "step";
    char* ptr2 = "steps";
    char* ptr3 = "stripe";
    char* ptr4 = "stepple";
    
    words[0] =  ptr1;
    words[1] =  ptr2;
    words[2] =  ptr3;
    words[3] =  ptr4;
    

    char s[7];
    strcpy(s,shortestCompletingWord(licensePlate, words, wordsSize));
    printf("%s", s);

    free(words);

}
// parte feita em casa acima:


//parte feita em aula abaixo:
char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){

    char licenseAdapted[sizeof(licensePlate)];
    int tempLetters[150] = {0};
    int letters[150] = {0};
    int letterCheck = 0;
    char* smallestWord;
    int smallestIndex;
    int teste = 0;
    int j = 0;

    for(int i = 0; i < sizeof(licensePlate); i++)
    {
        licenseAdapted[i] = '\0';
    }

    for(int i = 0; i < strlen(licensePlate); i++)
    {
        if(isdigit(licensePlate[i]) || licensePlate[i] == ' ')
        {
            continue;
        }

        licensePlate[i] = tolower(licensePlate[i]);

        licenseAdapted[j] = licensePlate[i];
        j++;

    }

    for(int i = 0; i < strlen(licenseAdapted); i++)
    {
        letters[(int)licenseAdapted[i]]++;
    }

    for(int i = 0; i < wordsSize; i++)
    {
        memcpy(tempLetters, letters, sizeof(letters));

        for(int c = 0; c < strlen(words[i]); c++)
        {
            if(tempLetters[(int)words[i][c]] > 0)
            {
                tempLetters[(int)words[i][c]]--;
            }
        }

        int sum = 0;

        for(int k = 0; k < 150; k++)
        {
            sum = sum + tempLetters[k];
        }

        if(sum == 0)
        {
            if(teste == 0)
            {
                smallestWord = words[i];
                smallestIndex = i;
                teste++;
            }
            else if(strlen(words[i]) < strlen(smallestWord))
            {
                smallestWord = words[i];
                smallestIndex = i;
            }
            else if(strlen(words[i]) == strlen(smallestWord))
            {
                if(i < smallestIndex)
                {
                    smallestWord = words[i];
                    smallestIndex = i;
                }
            }

        }
    }

    return smallestWord;
}