int mySqrt(int x){

long i = 0;

   if(x != 0)
   {
    while(i*i < x)
    {
        i++;        
    }
   }
   if(i*i> x)
   {
       i--;
   }

   return i;
}