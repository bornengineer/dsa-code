#include<bits/stdc++.h>
using namespace std;

// using template to avoid the restriction of data types
// when storing other data types in the stack
template<typename T>

class StackUsingArray{
    T *data;
    int nextIndex;
    int capacity;

    public:

    // StackUsingArray(int totalSize) {
    //     data = new int[totalSize];
    //     nextIndex = 0;
    //     capacity = totalSize;
    // }

    // constructor for dynamic size
    StackUsingArray() {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size() { return nextIndex; }

    bool isEmpty() { return nextIndex == 0; }

    void push(T value) {
        if(nextIndex == capacity) {
            // increasing the size of array to double to store more elements
            int *newData = new T[2 * capacity];
            for(int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
            // cout<<"Stack Full"<<endl;
            // return;
        }
        data[nextIndex++] = value;
    }

    T pop() {
        if(isEmpty()) {
            cout<<"Stack Empty"<<endl;
            // return INT_MIN; 
            // returning 0 cause it will also work for char and other data types
            return 0;
        }
        nextIndex--;
        return data[nextIndex];        
    }

    T top(){
        if(isEmpty()) {
            cout<<"Stack Empty"<<endl;
            return 0;
        }
        return data[nextIndex - 1];
    }

};

int main(){

    // Implementing the Stack created using Array
    // StackUsingArray s(5);

    // making the stack dynamic in size
    StackUsingArray<int> s;
    s.push(10);
    cout<<s.top()<<endl;
    s.push(20);
    cout<<s.top()<<endl;
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<"size:"<<s.size()<<endl;
    s.pop();
    cout<<"pop: "<<s.pop()<<endl;
    cout<<"pop: "<<s.pop()<<endl;
    cout<<(s.isEmpty() ? "True" : "False")<<endl;

    return 0;
}