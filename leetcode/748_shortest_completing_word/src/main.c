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