bool isPerfectSquare(int num){

unsigned short end = 46341;
unsigned short mid = end/2;
unsigned short pastMid;

    do{
        pastMid = mid;
        if(mid*mid < num)
        {
            mid = ((end-mid)/2) + mid;
        }
        if(mid*mid > num)
        {
            end = mid;
            mid = mid/2;
        }
    } while(mid != pastMid);

    if(mid*mid != num) return false;

    return true;
}