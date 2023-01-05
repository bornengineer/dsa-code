#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    vector<int> temp(a);
    sort(temp.begin(), temp.end());
    int med = temp[(n+1)/2 - 1];

    int newMed = med;
    while(newMed == med){
        a[k-1]++;
        vector<int> temp1(a);
        sort(temp1.begin(), temp1.end());
        newMed = temp1[(n+1)/2 - 1];
    }

    cout<<a[k-1] - 1;
    return 0;
}