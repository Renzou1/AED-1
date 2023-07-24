int mySqrt(int x){

unsigned int end = 65536; // square of max value 
unsigned int middle = end/2;

    while(middle*middle != x)
    {
        if(middle*middle < x)
        {
            middle = ((end-middle)/2) + middle;
        }
        if(middle*middle > x)
        {
            end = middle;
            middle = middle/2;
        }
        if(middle*middle < x && (middle+1)*(middle+1) > x)
        {
            return middle;
        }
    }
   return middle;
}