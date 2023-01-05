#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<(q.empty() ? "True" : "False")<<endl;

    cout<<endl<<"Loop Starts:"<<endl;
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    // output:
    // 6
    // 10
    // 30
    // 4
    // False

    // Loop Starts:
    // 30
    // 40
    // 50
    // 60

    return 0;
}