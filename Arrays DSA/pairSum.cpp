#include <bits/stdc++.h>
using namespace std;

// i've solved all 2sum, 3sum and 4sum on leetcode, have a look there
int pairSum(int array[], int size, int n)
{
    // naive approach
    int cnt = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] + array[j] == n)
            {
                cnt++;
                // to check the iterations
                // cout<<array[i]<<":"<<i<<" "<<array[j]<<":"<<j<<" "<<cnt<<endl;
            }
        }
    }
    return cnt;

    // better approach but can't handle one case of duplicates
    // int cnt = 0;
    // sort(array, array + size);
    // int i = 0;
    // int j = size - 1;
    // while (i != j)
    // {
    //     if (array[i] + array[j] < n)
    //     {
    //         i++;
    //     }
    //     else if (array[i] + array[j] > n)
    //     {
    //         j--;
    //     }
    //     else
    //     {
    //         cnt++;
    //     }
    // }
    // return cnt;
}

int main()
{
    int arr[] = {1, 3, 6, 2, 5, 4, 3, 2, 4};
    // int arr[] = {2,2,2,2,2};
    // int arr[] = {2, 8, 10, 5, -2, 5};
    // int arr[] = {6, -8, 4, 1, -6, 2, -4, 15};
    int num = 7;
    int len = sizeof(arr) / sizeof(arr[0]);
    int result = pairSum(arr, len, num);
    cout << result << endl;
    return 0;
}