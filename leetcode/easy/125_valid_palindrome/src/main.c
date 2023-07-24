/*A phrase is a palindrome if, 
after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/

bool isPalindrome(char * s){

int j = 0;
char t[strlen(s) + 1];

    for(int i = 0; i < strlen(s) + 1; i++)
    {
        t[i] = '\0';
    }

   for(int i = 0; i < strlen(s); i++)
   {
       if(isalnum(s[i])) 
       {
            t[j] = tolower(s[i]);
            j++;
       }
   }

    for(int i = 0; i < strlen(t) ; i++) 
    {
        if(t[i] == t[strlen(t)- i -1]) //-1 pois strlen e bugado
        {
            continue;
        }
        else{
        return false;
        }
    }
    return true;
}