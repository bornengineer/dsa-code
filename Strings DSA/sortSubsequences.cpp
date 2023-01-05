#include<bits/stdc++.h>
using namespace std;

void subsequences(int idx, string str, int n, string& ds, vector<string>& res){

    if(idx == n){
        res.push_back(ds);
        return;
    }

    subsequences(idx+1, str, n, ds, res);

    ds.push_back(str[idx]);

    subsequences(idx+1, str, n, ds, res);
    ds.pop_back();
}

bool compare(string s1 , string s2){
    if(s1.length() == s2.length()){
        return s1 < s2;
    }else{
        return s1.length() < s2.length();
    }
}

int main(){
    string str = "abcd";
    int n = str.length();
    
    vector<string> res;
    string ds;
    subsequences(0 , str, n, ds, res);
    sort(res.begin(), res.end(), compare);
    for(auto i : res)cout<<i<<endl;
    cout<<endl;
    return 0;
}