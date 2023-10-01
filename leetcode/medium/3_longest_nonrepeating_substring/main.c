int lengthOfLongestSubstring(char * s){
    int longest = 0;
    int current[128] = {0};
    int length = 0;
    int temp = 0;

    int start = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(current[s[i]] == 0)
        {
            length++;

        }  else
        {
            if(length > longest)
            {
                longest = length;
            }
            length = 1;
            temp = i;
            i = current[s[i]];

            for(int j = start; j <= temp; j++)
            {
                current[s[j]] = 0;
            }

            start = i;

        }
            
        current[s[i]] = i + 1;
    }

    if(length > longest)
    {
        longest = length;
    }
    return longest;
}
