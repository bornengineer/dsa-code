#include <bits/stdc++.h>
using namespace std;

void findIntersection(int array1[], int size1, int array2[], int size2)
{
    // naive approach O(size1Xsize2)
    // for (int i = 0; i < size1; i++)
    // {
    //     for (int j = 0; j < size2; j++)
    //     {
    //         if (array1[i] == array2[j])
    //         {
    //             cout << array1[i] << " ";
    //             array2[j] = INT_MIN;
    //         }
    //     }
    // }

    // O(nlogn) approach
    sort(array1, array1 + size1);
    sort(array2, array2 + size2);
    int diff = size1 - size2;
    for (int i = size1 - 1; i > 0; i--)
    {
        if (array1[i] == array2[i - diff])
        {
            cout << array1[i] << " ";
            array2[i-diff] = INT_MIN;
        }
    }
}

int main()
{
    int arr1[] = {6, 2, 6, 2, 1, 9, 8};
    int arr2[] = {3, 6, 8, 2, 9};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    findIntersection(arr1, len1, arr2, len2);
    return 0;
}