// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
        void reverse(string &str, int s, int e ){
        while(s<e){
        char temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        s++;
        e--;
        }
    }
    
    string reverseWords(string s) {
        int start = 0;
        int end = s.size() - 1;
        reverse(s, start, end);
        int j=0;

        for(int i = 0; i<=s.size(); i++){
            if(s[i] == '.' || i == s.size()){
                reverse(s, j, i - 1);
                j = i+1;
            }
        }
        // cout<<s<<endl;
    return s;
    }
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends