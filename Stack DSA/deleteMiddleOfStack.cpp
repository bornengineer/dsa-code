//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    
    void delMid(stack<int>&s, int size, int cnt){
        if(cnt == size/2){
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        delMid(s, size, cnt+1);
        s.push(temp);
    }
    
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int cnt = 0;
        delMid(s, sizeOfStack, cnt);
        
        // code here..
        // stack<int> temp;
        // int i = 0;
        // while(i < sizeOfStack/2){
        //     temp.push(s.top());
        //     s.pop();
        //     i++;
        // }
        // s.pop();
        // while(!temp.empty()){
        //     s.push(temp.top());
        //     temp.pop();
        // }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends