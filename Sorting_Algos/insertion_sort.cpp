#include<bits/stdc++.h>
using namespace std;
// We are just inserting the current element in the
// already sorted array at the right position TC - O(n^2)
int main(){
    vector<int> arr{20, 5, 40 , 60, 10, 30};
    int n = arr.size();
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        // j becomes -1 in first pass (just saying)
        arr[j+1] = key;
    }
    for(auto &i : arr)cout<<i<<" ";
    return 0;
}