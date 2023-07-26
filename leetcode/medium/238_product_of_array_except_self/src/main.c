/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 const int OFFSET = +30;

int* productExceptSelf(int* nums, int numsSize, int* returnSize){

    int* answer = (int*)malloc(sizeof(int) * numsSize);
    int possibles[61] = {0};
    int product = 1;

    for(int i = 0; i < numsSize; i++)
    {
        if(possibles[nums[i]+OFFSET] == 0)
        {
            for(int c = 0, teste = false; c < numsSize; c++)
            {
                if(c != i)
                {
                    product*= nums[c];
                } 
            }
            possibles[nums[i]+OFFSET] = product;
            answer[i] = product;
            product = 1;
        }
        else
        {
            answer[i] = possibles[nums[i] + OFFSET];
        }
    }
    *returnSize = numsSize;
    return answer;
}