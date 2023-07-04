bool isPerfectSquare(int num){
bool A = true;
long i = 0;
    if(num != 0)
    {
        while(i*i < num)
        {
            i++;
        }
        if(i*i > num)
        {
            A = false;
        }
    }
    return A;
}