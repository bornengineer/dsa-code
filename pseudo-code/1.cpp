#include<bits/stdc++.h>
using namespace std;

int fun(int a, int b){
    if((b-6) > (a&b) && b<a){
        a = a+1;
        b = a+2;
        return fun(a, b+1);
    }
    return a;
}

    int func(int a , int b , int c){
        c = (b+c) + a;
        if((c+a)<a && (c&3) < a){
            b = (a+7) + c;
            c = (15) + b;
        }
        return a + b + c;
    }

    int funcc(int a, int b, int c){
        b = (b+9) + c;
        c = (b+2) & a;
        b = b & c;
        c = 3 & a;
        c = (a+c) + c;
        return a + b + c;
    }

int main(){
    // int j;
    // vector<int> arr = {3,2,0,2};
    // arr[2] = arr[3] + arr[2];
    // for(j = 5; j<=6 ; j++){
    //     arr[j%3] = (arr[1] + 3) + arr[0];
    // }
    // cout<<arr[2] + arr[3]<<endl;
    // return 0;

    // int p, q,r;
    // p = 6;
    // q =2 ;
    // r= 8;
    // if((r+p) > (p-r) && r<q)r=q+r;

    // cout<<p+q+r;

    // cout<<func(4,7,8);

    // cout<<fun(8,7);

    // cout<<funcc(9,3,9);

    int j;
    vector<int> arr = {1,3,4,3};
    if((arr[0] + arr[2]) < (arr[2] - arr[0])){
        arr[2] = arr[3]^arr[0];
    }
    arr[3] = arr[1] + arr[0];
    if((arr[3] + arr[0]) > (arr[0] - arr[3])){
        arr[0] = (arr[0] + arr[1] + arr[0]);
    }
    cout<<arr[0] + arr[2];

}