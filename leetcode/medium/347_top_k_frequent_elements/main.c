/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int integers[20001] = {0};
    int integersSize = 20001;
    int lowestIndex;
    bool teste = true;
    int i;

    for(int i = 0; i < numsSize; i++)
    {
        integers[nums[i] + 10000]++;
        if(nums[i] + 10000 < lowestIndex || teste == true)
        {
            lowestIndex = nums[i] + 10000;
            teste = false;
        }
    }

    int kArray[k];
    int iArray[k];

    for(int i = 0; i < k; i++)
    {
        kArray[i] = 0;
        iArray[i] = 0;
    }

    for(int i = lowestIndex; i < integersSize; i++)
    {
        if(integers[i] == 0) continue;

        for(int j = 0; j < k; j++)
        {
            if(integers[i] > kArray[j])
            {
                for(int t = k - 2; t >= j; t--)
                {
                    kArray[t + 1] = kArray[t];
                    iArray[t + 1] = iArray[t];
                }
                kArray[j] = integers[i];
                iArray[j] = i;
                break;
            }
        }
    }
    int* returnArr = (int*)malloc(sizeof(int)* k);
    for(int i = 0; i < k; i++)
    {
        returnArr[i] = iArray[i] - 10000;
    }
    *returnSize = k;
    return returnArr;
}
