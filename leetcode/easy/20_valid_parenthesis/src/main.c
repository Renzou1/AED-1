bool isValid(char * s){
    char toClear[strlen(s)+2];
    int top = 0;

    for(int i = 0; i < strlen(s) + 1; i++)
    {
        toClear[i] = '\0';
    }

    for(int i = 0; i < strlen(s); i++)
    {
        switch(s[i])
        {
            case '(':
            top++;
            toClear[top] = '(';
            break;

            case '[':
            top++;
            toClear[top] = '[';
            break;

            case '{':
            top++;
            toClear[top] = '{';
            break;


            case ')':
            if(toClear[top] != '(') return false;
            toClear[top] = '\0';
            top--;
            break;

            case ']':
            if(toClear[top] != '[') return false;
            toClear[top] = '\0';
            top--;
            break;
            
            case '}':
            if(toClear[top] != '{') return false;
            toClear[top] = '\0';
            top--;
            break;
        }
    }
    return toClear[top] == '\0';
}