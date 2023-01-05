#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{0, -1, 4, 434 ,23, 33, 5};
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        // optimizing bubble sort by using bool swapped if the array is sorted
        // or becomes sorted then the further iterations will be avoided
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            cout<<"Not swapped"<<endl;
            break;
        }
    }
    for(auto &i : arr)cout<<i<<" ";
    return 0;
}
// TC - O(n^2)
// Stable - Yes (cause it doesn't change order of equal elements)