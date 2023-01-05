#include <bits/stdc++.h>
using namespace std;

int findUnique(int array[], int size)
{
    // naive approach1 O(n^2)
    for (int i = 0; i < size; i++)
    {
        int cnt = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j] && i != j)
                cnt++;
        }
        if (cnt == 0)
            return array[i];
    }
    return INT_MIN;

        // // naive approach2
        // // time complexity - O(n^2)
        // for(int i = 0 ; i < size ; i++){
        //     for(int j = 0 ; j < size ;){
        //         if(j == i){
        //             j++;
        //         }else if(array[j] != array[i]){
        //             // cout<<"*"<<endl;
        //             continue;
        //         }
        //         else if(array[j] == array[i]){
        //             break;
        //         }else{
        //             return array[i];
        //         }
        //     }
        // }
        // return -1;

    // better approch nlogn
    // sort(array, array + size);
    // for (int i = 0; i < size; i += 2)
    // {
    //     if (array[i] != array[i + 1])
    //     {
    //         return array[i];
    //     }
    // }
    // return INT_MIN;

    // optimal solution O(n)
    // int xorr = 0;
    // for(int i = 0; i < size; i++) {
    //     xorr = xorr ^ array[i];
    // }
    // return xorr;
}

int main()
{
    // int arr[] = {2, 6, 8, 5, 6, 2, 8};
    int arr[] = {1, 1, 2, 2, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    int result = findUnique(arr, len);
    cout << result << endl;
    return 0;
}

// i had solved in this way earlier
// int findUnique(int array[] , int size){
//     // naive approach
//     // time complexity - O(n^2)
//     for(int i = 0 ; i < size ; i++){
//         for(int j = 0 ; j < size ;){
//             if(j == i){
//                 j++;
//             }else if(array[j] != array[i]){
//                 continue;
//             }
//             else if(array[j] == array[i]){
//                 break;
//             }else{
//                 return array[i];
//             }
//         }
//     }

//     // other approach after sorting the array
//     // time complexity - O(nlogn)
//     // std::sort(array, array+size);
//     // for(int i = 0 ; i < size ;){
//     //     if(array[i] == array[i+1]){
//     //         i+=2;
//     //     }else{
//     //         return array[i];
//     //     }
//     // }

//     // xor approach
//     // time complexity - O(n)
//     //     int xxor = 0;
//     // for(int i = 0 ; i < size ; i++){
//     //     xxor ^= array[i];
//     // }
//     //     return xxor;

// };