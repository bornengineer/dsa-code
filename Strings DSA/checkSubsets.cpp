#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "codongmonutes";
    string s2 = "cines";

    int i = s2.size() - 1;
    int j = s1.size() - 1;

    while(j>=0){
        if(s2[i] == s1[j]){
            j--;
            i--;
        }else{
            j--;
        }
    }

    if(i<0)cout<<1<<endl;

    else cout<<0<<endl;


    return 0;
}