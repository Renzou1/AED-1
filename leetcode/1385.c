/* problema 1385: Given two integer arrays arr1 and arr2, and the integer d, 
return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i] such that 
there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

Enunciado é bem ruim, explicação melhor nos comentários do problema*/

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d)
{
    
    int distancia_de_zero;
    int distance_value;
    int falses = 0;
    int output = 0;

    for (int i = 0; i < arr1Size; i++)
    {
        falses = 0;

        for(int j = 0; j < arr2Size; j++)
        {
            int temp = arr1[i] - arr2[j];
            
            if(temp > 0)
            {
                distance_value = temp;
            }
            else
            {
                distance_value = -temp;
            }

            if(distance_value > d)
            {
                falses++;
            }

            if(falses == arr2Size)
            {
                output++;
            }

        }
    }
    return output;
}