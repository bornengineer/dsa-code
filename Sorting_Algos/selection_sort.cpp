#include<bits/stdc++.h>
using namespace std;
// in each pass put the min element at the start of array
int main(){
    vector<int> arr{10, 5, 8 ,20, 2, 18};
    int n = arr.size();
    // iterate till n-1 cause only one element will be left
    for(int i=0; i<n-1; i++){
        int mindex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[mindex]){
                mindex = j;
            }
        }
        swap(arr[mindex], arr[i]);
    }
    for(auto &i : arr)cout<<i<<" ";
    return 0;
}