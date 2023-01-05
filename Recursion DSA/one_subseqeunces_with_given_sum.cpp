#include<bits/stdc++.h>
using namespace std;

void print (vector<int> &ds){
    for(auto i : ds){ cout << i <<" ";}
    cout << endl;
}

bool subseqeunces_with_given_sum(int idx, vector<int>&ds, int s, vector<int>& nums, int n, int sum){
    if(idx==n){
        if(s == sum){
            print(ds);
            return true;
        }
        return false;
    }
    ds.push_back(nums[idx]);
    s += nums[idx];
    if(subseqeunces_with_given_sum(idx+1, ds, s, nums, n, sum) == true)return true;

    ds.pop_back();
    s -= nums[idx];
    if(subseqeunces_with_given_sum(idx+1, ds, s, nums, n, sum) == true)return true;

    return false;
}

int main(){
    vector<int> nums = {1,2,1};
    int n = nums.size();
    int sum = 2;
    vector<int>ds;
    subseqeunces_with_given_sum( 0, ds, 0, nums, n, sum);
    return 0;
}