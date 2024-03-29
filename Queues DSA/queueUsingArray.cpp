#include<bits/stdc++.h>
using namespace std;

template<typename T>

class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s){
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize() { return size; }

    bool isEmpty() { return size == 0; }

    void enqueue(T element) {
        if(size == capacity){
            // Creating dynamic queue
            T *newData = new T[capacity * 2];
            int j = 0;
            for(int i = firstIndex ; i<capacity ; i++){
                newData[j] = data[i];
                j++;
            }
            for(int i = 0; i<firstIndex ; i++){
                newData[j] = data[i];
                j++;
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;

            // cout<<"Queue is Full!"<<endl;
            // return;
        }

        
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }

    T dequeue() {
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;

        // agar size zero hojay to reset krne ke liye
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans;
    }

    T front(){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

};

int main(){
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<<q.getSize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<(q.isEmpty() ? "True" : "False")<<endl;

    return 0;
}