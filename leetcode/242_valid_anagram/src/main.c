bool isAnagram(char * s, char * t){
    int A[26] = {0};

    if(strlen(s) != strlen(t)) return false;

    for(int i = 0; i < strlen(s); i++)
    {
        A[(int)s[i]-97]++;
    }
    for(int c = 0; c < strlen(t); c++)
    {
        A[(int)t[c]-97]--;
    }

    for(int j = 0; j < 26; j++)
    {
        if(A[j] != 0) return false;
    }

    return true;
}