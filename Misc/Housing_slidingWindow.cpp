#include<bits/stdc++.h>
using namespace std;

void housing(vector<int>& plots, int k){
    int i = 0;
    int j = 0;
    int currSum = 0;
    while(j<plots.size()){
        currSum += plots[j];
        j++;
        while(currSum > k and i<j){
            currSum -= plots[i];
            i++;
        }
        if(currSum == k){
            cout<<i<<" "<<j-1<<endl;
        } 
    }
}

int main(){
    vector<int> plots = {1,3,2,1,4,1,3,2,1,1};
    int k = 8;
    housing(plots, k);
    return 0;
}