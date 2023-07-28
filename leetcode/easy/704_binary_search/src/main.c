int search(int* nums, int numsSize, int target){

    
    int mid = (numsSize-1)/2;
    int end = numsSize-1;
    int pastMid = -1;

    while(nums[mid] != target && mid != pastMid)
    {
       if(nums[mid] < target) 
       {
           pastMid = mid;
           mid = ((end-mid)/2) + mid;
       }
       if(nums[mid] > target)
       {
           end = mid;
           pastMid = mid;
           mid = mid/2;
       }
    }

    if(nums[mid] == target) return mid;
    if(nums[end] == target) return end;
    return -1;
}