/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){

    int smaller = target/2;
    int bigger = target/2;
    int index1;
    int index2;
    bool first = true;

    if(smaller + bigger < target)
    {
        bigger = bigger + 1;
    }  else if (smaller + bigger > target)
        {
        smaller = smaller - 1;
        } 


    index1 = numbersSize - 1;
    index2 = numbersSize - 1;

    do{
        while(numbers[index1] > smaller)
        {
            index1--;
        }
        while(index1 - 1 >= 0)
        {
            if(numbers[index1 - 1] == numbers[index1])
            {
                index1 = index1 - 1;
            }  else break;
        }

        if(numbers[index1] < smaller)
        {
            smaller = numbers[index1];
            bigger = target - smaller;
        }
        
        if(first == true)
        {
            index2 = index1 + 1;
            first = false;
        }

        while(numbers[index2] < bigger)
        {
            index2++;
        }

        if(numbers[index2] > bigger)
        {
            bigger = numbers[index2];
            smaller = target - bigger;
        }

    } while(numbers[index1] + numbers[index2] != target);
    
    *returnSize = 2;
    int* returnArr = (int*)malloc(sizeof(int)*2);
    *(returnArr) = index1 + 1;
    *(returnArr + 1) = index2 + 1;
    return returnArr;
    
}
