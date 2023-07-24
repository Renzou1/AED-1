void RenzoSort(int* nums);

bool containsDuplicate(int* nums, int numsSize){

    RenzoSort(nums);
    for(int i = 0; i < numsSize-1; i++)
    {
        if(nums[i] == nums[i+1])
        {
            return true;
        }
    }
    return false;
}

void RenzoSort(int* nums)
{
    int indexOfSmallest = 0;
    int temp = 0;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    for(int i = 0; i < numsSize; i++)
    {
        indexOfSmallest = i;
        for(int c = i + 1; c < numsSize; c++)
        {
            if(nums[c] < nums[indexOfSmallest])
            {
                indexOfSmallest = c;
            }
        }
        temp = nums[i];
        nums[i] = nums[indexOfSmallest];
        nums[indexOfSmallest] = temp;
    }
}