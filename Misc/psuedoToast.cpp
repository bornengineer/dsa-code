#include<bits/stdc++.h>
using namespace std;

void func(string s){
    int mlen = 1;
    int beg = 0;
    int len = s.size();
    int low , high;
    for(int i = 1; i<=len; i++){
        low = i-1;
        high = i;
        while(low>=0 && high<len && s[low]==s[high]){
            --low;
            ++high;
        }
        ++low;
        --high;
        if(s[low]==s[high] && (high - low + 1) > mlen){
            beg = low;
            mlen = high - low + 1;
        }
        low = i-1;
        high = i+1;
        while(low>=0 && high<len && s[low]==s[high]){
            --low;
            ++high;
        }
        ++low;
        --high;
        if(s[low] == s[high] && (high - low + 1) > mlen){
            beg = low;
            mlen = high - low + 1;
        }
    }
    int ans = mlen;
    while(ans--){
        cout<<s[beg++];
    }
}

int main(){
    string s = "HACKEREARTH";
    func(s);
    return 0;
}