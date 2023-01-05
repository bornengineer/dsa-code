#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData = 0;
    cout<<"Enter root data: "<<endl;
    cin>>rootData;
    if(rootData == -1)return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int leftChild;
        cout<<"Enter left child of "<<front->data<<endl;
        cin>>leftChild;
        if(leftChild != -1){
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            front->left = leftNode;
            pendingNodes.push(leftNode);
        }

        int rightChild;
        cout<<"Enter right child of "<<front->data<<endl;
        cin>>rightChild;
        if(rightChild != -1){
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            front->right = rightNode;
            pendingNodes.push(rightNode);
        }
    }
    return root;
}

void printTreeLevelOrder(BinaryTreeNode<int>* root){
    cout<<endl<<"Printing tree in level order: "<<endl;
    if(!root)return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<" : ";

        if(front->left){
            cout<<"L:"<<front->left->data<<" , ";
            pendingNodes.push(front->left);
        }
        else{
            cout<<"L:"<<"_"<<" , ";
        }

        if(front->right){
            cout<<"R:"<<front->right->data<<endl;
            pendingNodes.push(front->right);
        }
        else{
            cout<<"R:"<<"_"<<endl;
        }
    }
}

bool searchInBST(BinaryTreeNode<int>* root, int num){
    if(!root)return false;

    if(root->data == num)return true;
    else if(num < root->data)return searchInBST(root->left,num);
    else return searchInBST(root->right,num);
}

void elementsBwK1K2(BinaryTreeNode<int>* root, int k1, int k2, vector<int>& res){
    if(!root)return;

    if(root->data > k2) elementsBwK1K2(root->left,k1,k2,res);
    else if(root->data < k1) elementsBwK1K2(root->right,k1,k2,res);
    else{
        elementsBwK1K2(root->left,k1,k2,res);
        res.push_back(root->data);
        elementsBwK1K2(root->right,k1,k2,res);
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelOrder(root);
    // int num;
    // cin>>num;
    // cout<<(searchInBST(root, num) ? "true" : "false")<<endl;
    
    int k1 = 6, k2 = 10;
    vector<int> res;
    elementsBwK1K2(root,k1,k2,res);
    for(auto i:res)cout<<i<<" ";
    cout<<endl;

    
}