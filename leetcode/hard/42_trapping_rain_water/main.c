int trap(int* height, int heightSize){
    if(heightSize <= 1) return 0;

    int p1 = 0;
    int p2 = 0;
    int total_water = 0;
    int temp_water;

    while(p1 < heightSize && p2 < heightSize)
    {
        p2++;
        if(p2 >= heightSize) break;

        while(height[p2] < height[p1])
        {
            temp_water+= height[p1] - height[p2];
            p2++;
            if(p2 >= heightSize) break;
        }  

        if(p2 >= heightSize)
        {
            height[p1]--;
            p2 = p1;

        }  else if(height[p2] >= height[p1])
        {
            total_water += temp_water;
        } 

        p1 = p2;
        temp_water = 0;
    }
    return total_water;
}
