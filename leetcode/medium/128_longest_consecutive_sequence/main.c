void merge(const int arr[], int size1, const int arr2[], int size2, int final[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < size1 && j < size2)
    {
        if(arr[i] < arr2[j])
        {
            final[k] = arr[i];
            i++;
        }  else{
            final[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i < size1)
    {
        final[k] = arr[i];
        i++;
        k++;
    }
    while(j < size2)
    {
        final[k] = arr2[j];
        j++;
        k++;
    }

}

void merge_sort(int arr[], int size)
{
    if(size < 2) return;
    int mid = size/2;
    int i = 0;
    int left[mid];
    for(i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    int right[size - (i-1)];
    while(i < size)
    {
        right[i - mid] = arr[i];
        i++;
    }
    merge_sort(left, mid);
    merge_sort(right, size-mid);
    merge(left, mid, right, size-mid, arr);
}



int longestConsecutive(int* nums, int numsSize){

    if(numsSize == 0) return 0;

    merge_sort(nums, numsSize);

    int biggest = 1;
    int current; 
    for(int i = 1; i < numsSize; i++)
    {
        current = 1;

        while(i < numsSize)
        {
            if(nums[i] == nums[i-1] + 1)
            {
                current++; // maybe add the difference between num[i] and num[i-1], and remove ifs
                i++;

            }   else if(nums[i] == nums[i-1])
                {
                    i++;

                }  else break;
        }

        if(current > biggest)
        {
            biggest = current;
        }
    }

    return biggest;
}
