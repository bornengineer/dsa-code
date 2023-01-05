#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestPalindromic(string num) { 
        int n = num.size();
        string s;
        vector<int> freq(10,0);
        for(int i = 0; i<10; i++){
            char ch = i+48;
            for(int j = 0; j<n ; j++){
                if(ch == num[j]){
                    freq[i]++;
                }
            }
        }
        // for(auto i:freq)cout<<i<<" ";
        // cout<<endl;
        
        int mid;
        for(int i = 0 ; i<10 ; i++){
            if(freq[i]%2 == 1){
                mid = i;
                freq[i]--;
            }
        }
        // cout<<mid<<endl;

        
        for(int i = 9 ; i>=0; i--){
                if(freq[i]>0 && freq[i]%2 != 0)freq[i]--;
                if(freq[i]%2 == 0){
                    char ch = i+48;
                    for(int j=0, size = freq[i]/2 ; j<size; j++){
                        s += ch;
                        freq[i]--;
                    } 
                }                
        }
        
        char midchar = mid + 48;
        s += midchar;
        
        for(int i = 0 ; i<10; i++){
                char ch = i+48;
                while(freq[i]--)s+=ch;
        }
        
        // cout<<s<<endl;
        // for(auto i:freq)cout<<i<<" ";
        // cout<<endl;
        
        for(int i = 0; i<s.size()/2; i++){
            char ch = 48;
            if(s[i] == ch){
                s.erase(i,1);
                s.erase(s.size()-i-1,1);
                i--;
            }
            else break;
        }

        return s;
    }
};

int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.largestPalindromic(s);
}