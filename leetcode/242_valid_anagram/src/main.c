bool isAnagram(char * s, char * t){
    int A[26] = {0};

    if(strlen(s) != strlen(t)) return false;

    for(int i = 0; i < strlen(s); i++)
    {
        A[s[i]-'a']++;
    }
    for(int c = 0; c < strlen(t); c++)
    {
        A[t[c]-'a']--;
    }

    for(int j = 0; j < 26; j++)
    {
        if(A[j] != 0) return false;
    }

    return true;
}