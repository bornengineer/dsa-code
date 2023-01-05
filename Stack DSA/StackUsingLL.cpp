#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{
    Node<T> *head;
    int size;

    public:
    Stack(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return head == NULL;
    }

    void push(T val){
        Node<T> * newNode = new Node<T>(val);
        newNode -> next = head;
        head = newNode;
        size++;
    }

    int pop(){
        if(isEmpty()) return 0;
        T ans = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        size--;
        return ans;        
    }

    int top(){
        if(isEmpty()) return 0;
        return head -> data;
    }

};

int main(){

    // Implementing the Stack created using Linked list
    Stack<int> s;
    s.push(10);
    cout<<s.top()<<endl;
    s.push(20);
    cout<<s.top()<<endl;
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<"size:"<<s.getSize()<<endl;
    s.pop();
    cout<<"pop: "<<s.pop()<<endl;
    cout<<"pop: "<<s.pop()<<endl;
    cout<<(s.isEmpty() ? "True" : "False")<<endl;

    return 0;
}