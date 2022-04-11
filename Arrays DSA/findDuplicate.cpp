// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#include <iostream>

int findDuplicate(int array[], int size){
    // naive approach O(n^2)
    // for(int i = 0 ; i < size ; i++){
    //     for(int j = 0 ; j < size ; j++){
    //         if(j == i){
    //             j++;
    //         }
    //         if(array[j] == array[i]){
    //             return array[i];
    //         }
    //     }
    // }
    
    // O(nlogn)
    // std::sort(array, array + size);
    // for(int i= 0 ; i < size ;i++){
    //     if(array[i] == array[i+1]){
    //         return array[i];
    //     }
    // }
    
    // optimal solution O(n)
    int sum = 0;
    for (int i= 0 ; i < size ; i++){
        sum += array[i];
    }
    // std::cout<<sum<<std::endl;
    int sumOfNMinus2 = ((size - 1)*(size - 2)) /2;
    return sum - sumOfNMinus2;
}

int main() {
    // // Write C++ code here
    // std::cout << "Hello world!";

int arr[] = {0,7,2,5,4,2,1,3,6};
int len= sizeof(arr)/sizeof(arr[0]);
// std::cout<<len<<std::endl;
int result = findDuplicate(arr, len);
std::cout<<result<<std::endl;

    return 0;
}