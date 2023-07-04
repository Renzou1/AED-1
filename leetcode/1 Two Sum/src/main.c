/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int* V =(int *)malloc(sizeof(int)*2);
int i = 0;
int c = 0;
    for(i = 0; i < numsSize; i++)
    {
        for(c = 0; c < numsSize; c++)
        {
            if(nums[i] + nums[c] == target)
            {
                if(i != c)
                {
                    V[0] = c;
                    V[1] = i;
                    break;
                }
            }
        }
    }

    *returnSize = 2;
    return V;
}