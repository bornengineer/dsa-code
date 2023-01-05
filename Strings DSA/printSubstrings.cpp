#include <bits/stdc++.h>
using namespace std;

void printSubstrings(string s){

    // Using 3 for loop O(n^3) naive approach

    // for(int i = 0 ; i < s.size(); i++){
    //     for(int j = i ; j < s.size() ; j++){
    //         for(int k = i; k <=j ; k++){
    //             cout<<s[k];
    //         }
    //         cout<<endl;
    //     }
    // }

    // using 2 for loops and appending the string
    // for(int i = 0 ; i < s.size() ; i++){
    //     string subStr;
    //     for(int j = i ; j < s.size() ; j++) {
    //         subStr += s[j];
    //         cout<<subStr<<endl;
    //     }
    // }

    // using substr() fn O(n^2)
    for(int i = 0 ; i < s.size() ; i++) {
        for(int len = 1 ; len <= s.size() - i ; len++) {
            cout<<s.substr(i, len)<<endl;
        }
    }
}

int main() {
    string str = "abc";
    printSubstrings(str);
	return 0;
}