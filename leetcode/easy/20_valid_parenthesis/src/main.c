bool roundBrackets(char* s, int position);

bool squareBrackets(char* s, int position);

bool curlyBrackets(char* s, int position);


bool isValid(char * s){

    bool output = false;
    int sLength = strlen(s);

    for(int position = 0; position < sLength; position++)
    {
    
    switch(s[position])
    {
        case '(':
        output = roundBrackets(s, position);
        break;

        case '[':
        output = squareBrackets(s, position);

        case '{':
        output = curlyBrackets(s, position);

        default:
        output = false;
    }
        if(output == true)
        {
            break;
        }
    }

    return output;
}

bool roundBrackets(char* s, int position)
{
    bool output = false;
    int sLength = strlen(s);
    bool temp = true;

    for(int c = position; c < sLength; c++)
    {
        if(temp == true)
        {
        switch (s[c])
        {
            
            case ')':
            {
                output = true;
                break;
            }
            
            case '[':
            {
                temp = squareBrackets(s, c);
                c = c++;
                break;
                
            }

            case '{':
            {
                temp = curlyBrackets(s, c);
                c = c++;
                break;
            }
        }
        }


                
    }
    
    return output;
}

bool squareBrackets(char* s, int position)
{
    int output = false;
    int sLength = strlen(s);
    bool temp = true;

    for(int c = position; c < sLength; c++)
    {
        if(temp == true)
        {
        switch (s[c])
        {
            
            case ']':
            {
                output = true;
                break;
            }
            
            case '(':
            {
                temp = roundBrackets(s, c);
                c = c++;
                break;
                
            }

            case '{':
            {
                temp = curlyBrackets(s, c);
                c = c++;
                break;
            }
        }
        }
    }

    return output;
}

bool curlyBrackets(char* s, int position)
{
    int sLength = strlen(s);
    bool output = false;
    bool temp = true;

    for(int c = position; c < sLength; c++)
    {
        if(temp == true)
        {
        switch (s[c])
        {
            
            case '}':
            {
                output = true;
                break;
            }
            
            case '(':
            {
                temp = roundBrackets(s, c);
                c = c++;
                break;
                
            }

            case '[':
            {
                temp = squareBrackets(s, c);
                c = c++;
                break;
            }
        }
        }
    }

    return output;
}
