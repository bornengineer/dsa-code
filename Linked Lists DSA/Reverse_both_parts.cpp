//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    Node* reverseList(Node* head) {
        
        if(head == NULL || head -> next == NULL)return head;
        
        Node *smallAns = reverseList(head -> next);
        
        Node *tail = head -> next;
        tail -> next = head;    // or head -> next -> next = head;
        head -> next = NULL;
        
        return smallAns;
    }
   
    Node *reverse(Node *head, int k)
    {
        // code here
        int num = k-1;
        Node *temp = head;
        while(num){
            temp = temp -> next;
            num--;
        }
        Node *temp2 = temp -> next;
        temp -> next = NULL;
        temp = head;
        
        Node *ans1 = reverseList(head);
        
        Node *ans2 = reverseList(temp2);
        
        Node *temp3 = ans1;
        
        while(temp3 -> next){
            temp3 = temp3 -> next;
        }
        temp3 -> next = ans2;
        
        return ans1;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}  // } Driver Code Ends