void merge(int left[], int leftSize, int right[], int rightSize, int final[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < leftSize && j < rightSize)
    {
        if(left[i] < right[j])
        {
            final[k] = left[i];
            i++;
        }  else
        {
            final[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < leftSize)
    {
        final[k] = left[i];
        i++;
        k++;
    }
    while(j < rightSize)
    {
        final[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int nums[], int size)
{
    if(size < 2) return;

    int mid = size/2;
    int left[mid];
    int i = 0;

    while(i < mid)
    {
        left[i] = nums[i];
        i++;
    }
    int right[size - mid];
    while(i < size)
    {
        right[i - mid] = nums[i];
        i++;
    }
    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(left, mid, right, size-mid, nums);
}


bool containsDuplicate(int* nums, int numsSize){
    if(numsSize == 0) return false;

    merge_sort(nums, numsSize);
    
    int i = 1;
    while(i < numsSize)
    {
        if(nums[i] == nums[i-1]) return true;
        i++;
    }

    return false;
}
