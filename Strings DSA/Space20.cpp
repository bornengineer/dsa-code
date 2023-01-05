#include<bits/stdc++.h>
using namespace std;

int main(){
    string input = "h are ?";
    for(int i = input.size() - 1 ; i >= 0; i--){
        if(input[i] == ' '){
            input = input.substr(0,i) + "%20" + input.substr(i+1);
        }
    }
    cout<<input<<endl;
    return 0;
}