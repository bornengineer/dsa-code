#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &res){
    for(int i=0; i<res.size(); ++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

void nextGreatestElement(vector<int> &v){
    // brute force approach
    int n = v.size();
    vector<int> res(n, -1);
    for(int j = 0; j < n; ++j){
        for(int k = j + 1; k < 2*n; ++k){
            if(v[k%n]>v[j]){
                res[j] = v[k%n];
                break;
            }
        }
    }

    // optimal approach with stack
    // int n = v.size();
    // vector<int> res (n,-1);
    // stack<int> st;
    // for(int i = 2*n-1; i >= 0; --i){

    //     while(!st.empty() and st.top() <= v[i%n])st.pop();

    //     if(i<n){
    //         if(!st.empty()) res[i] = st.top();
    //     }
    //     st.push(v[i%n]);
    // }
    print(res);
};

int main(){
    vector<int> v = {4,5,2,25,7,8};
    vector<int> v2 = {4,12,5,3,1,2,5,3,1,2,4,6};
    nextGreatestElement(v);
    nextGreatestElement(v2);
    return 0;
}


        // if(st.empty()){
        //     res[i] = -1;
        //     st.push(v[i]);
        // }
        // else if(st.top() > v[i]){
        //     res[i] = st.top();
        //     st.push(v[i]);
        // }else{
        //     while(st.top() < v[i] || !(st.empty()))st.pop();
        //     if(st.empty()){
        //     res[i] = -1;
        //     st.push(v[i]);
        //     }
        //     else if(st.top() > v[i]){
        //         res[i] = st.top();
        //         st.push(v[i]);
        //     }
        // }