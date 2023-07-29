int firstUniqChar(char * s){
   int alphabet[26] = {0};
   int location[26] = {0};

    for(int i = 0; i < strlen(s); i++)
    {
        if(alphabet[s[i] - 'a'] == 0) 
        {
            location[s[i] - 'a'] = i;
        }
        alphabet[s[i] - 'a']++;
    }

    bool teste = false;
    int lowestIndex = -1;

    for(int i = 0; i < strlen(s); i++)
    {
        if(alphabet[s[i] - 'a'] == 1 && teste == false)
        {
            lowestIndex = location[s[i] - 'a'];
            teste = true;

        } else if(alphabet[s[i] - 'a'] == 1)
        {
            if(location[s[i] - 'a'] < lowestIndex)
                lowestIndex = location[s[i] - 'a'];
        }
    }

    return lowestIndex;

}