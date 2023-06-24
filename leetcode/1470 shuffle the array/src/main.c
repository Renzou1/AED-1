/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{

    int* new_nums = (int*)malloc(sizeof(int)*numsSize);

    for(int i = 0; i < n; i++)
    {
        new_nums[i*2] = nums[i];
        new_nums[i*2+1] = nums[i+n];
    }
    *returnSize = numsSize; 
    return new_nums;
}