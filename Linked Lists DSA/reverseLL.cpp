// ### this file has all the 3 approaches to reverse a linked list ###

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Making Pair class to represent and use tail of LL also
// class Pair {
// public:
//     ListNode *head;
//     ListNode *tail;
// };

class Solution
{
public:
    //     Pair reverseList_2(ListNode *head){
    //         if(head == NULL || head -> next == NULL){
    //             Pair ans;
    //             ans.head = head;
    //             ans.tail = head;
    //             return ans;
    //         }

    //         Pair smallAns = reverseList_2(head -> next);

    //         // here we can directly use SmallAns.tail
    //         smallAns.tail -> next = head;
    //         head -> next = NULL;

    //         Pair ans;
    //         ans.head = smallAns.head;
    //         ans.tail = head;

    //         return ans;
    //     }

    //     ListNode *reverseListHelper(ListNode *head){
    //         return reverseList_2(head).head;
    //     }

    // Recursive
    ListNode *reverseList(ListNode *head)
    {
        // best approach O(n)
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *smallAns = reverseList(head->next);

        ListNode *tail = head->next;
        tail->next = head; // or head -> next -> next = head;
        head->next = nullptr;

        return smallAns;

        // better recursive solution O(n) using Pair class
        // return reverseListHelper(head);

        // O(n^2)
        //         if(head == NULL || head -> next == NULL)return head;

        //         ListNode *smallAns = reverseList(head -> next);

        //         ListNode *temp = smallAns;
        //         while(temp -> next != NULL){
        //             temp = temp -> next;
        //         }

        //         temp -> next = head;
        //         head -> next = NULL;

        //         return smallAns;
    }
};

// Iterative
//     ListNode* reverseList(ListNode* head) {
//         ListNode *curr = head, *nxt = NULL, *prev = NULL;
//         while(curr != NULL){
//             // to keep the 2nd element's address before updating curr
//             nxt = curr -> next;
//             // putting prev (null at first) in curr
//             curr -> next = prev;
//             // updating both prev and curr
//             prev = curr;
//             curr = nxt;
//         }
//         return prev;
//     }
// };