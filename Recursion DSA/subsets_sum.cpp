#include<bits/stdc++.h>
using namespace std;

void print (vector<int> &ds){
    for(auto i : ds){ cout << i <<" ";}
    cout << endl;
}

void func(int idx, int sum, vector<int>& nums, vector<int>&res){
    if(idx==nums.size()){
        res.push_back(sum);
        return;
    }
    func( idx+1, sum + nums[idx], nums, res);

    func( idx+1, sum, nums, res);
}

int main(){
    vector<int> nums = {3,1,2};
    int n = nums.size();
    vector<int> res;
    func( 0, 0, nums, res);
    sort(res.begin(), res.end());
    print(res);
    return 0;
}