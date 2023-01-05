#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int cnt = 0;
    int a, b;
    for(int i = 0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int and = v[i] & v[j];
            int sum = (v[i] + v[j])/2;
            if(and == sum)cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}