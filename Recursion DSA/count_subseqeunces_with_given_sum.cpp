#include<bits/stdc++.h>
using namespace std;

int subseqeunces_with_given_sum(int idx, int s, vector<int>& nums, int n, int sum){
    if(idx==n){
        if(s == sum)return 1;
        else return 0;
    }
    s += nums[idx];
    int l = subseqeunces_with_given_sum(idx+1, s, nums, n, sum);

    s -= nums[idx];
    int r = subseqeunces_with_given_sum(idx+1, s, nums, n, sum);

    return l+r;
}

int main(){
    vector<int> nums = {1,2,1};
    int n = nums.size();
    int sum = 2;
    cout<<subseqeunces_with_given_sum( 0, 0, nums, n, sum)<<endl;
    return 0;
}