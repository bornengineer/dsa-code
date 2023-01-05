#include<bits/stdc++.h>
using namespace std;

void print (vector<int> &ds){
    for(auto i : ds){ cout << i <<" ";}
    cout << endl;
}

void subseqeunces_with_given_sum(int idx, vector<int>&ds, int s, vector<int>& nums, int n, int sum){
    if(idx==n){
        if(s == sum){
            print(ds);
        }
        return;
    }
    ds.push_back(nums[idx]);
    s += nums[idx];
    subseqeunces_with_given_sum(idx+1, ds, s, nums, n, sum);

    ds.pop_back();
    s -= nums[idx];
    subseqeunces_with_given_sum(idx+1, ds, s, nums, n, sum);
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    int n = nums.size();
    int sum = 6;
    vector<int>ds;
    subseqeunces_with_given_sum( 0, ds, 0, nums, n, sum);
    return 0;
}