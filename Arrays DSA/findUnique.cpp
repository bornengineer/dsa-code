#include <iostream>
using namespace std;

int findUnique(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;)
        {
            if (array[i] == array[j])
            {
                break;
                j++;
            }
            else{
                
            }
        }
    }
}

int main()
{
    int arr[100] = {2, 6, 8, 5, 6, 2, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    int result = findUnique(arr, len);
    return 0;
}