#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int childs;
    cout<<"Enter no. of children for "<< rootData<<endl;
    cin>>childs;
    for(int i=0;i<childs;i++){
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root){
    // we don't need a base case in case of generic trees
    // but if anyone passes a NULL tree when we need to handle this edge case
    if(root == NULL){
        return;
    }

    cout<<root->data<<": ";
    // to print the child nodes of every node
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}

TreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter no. of childs of "<<front->data<<endl;
        int numChilds;
        cin>>numChilds;

        for(int i=0; i<numChilds; i++){
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            int child;
            cin>>child;
            TreeNode<int>* childNode = new TreeNode<int>(child);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}

void printTreeLevelOrder(TreeNode<int>* root){
    cout<<endl<<"Printing tree in level order: "<<endl;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        cout<<front->data<<":";
        for(int i=0; i<front->children.size(); i++){
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout<<endl;
    }
}

int countNodes(TreeNode<int> *root){
    int ans = 1;
    for(int i=0; i<root->children.size(); i++){
        ans += countNodes(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int>* root){
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++){
        sum += sumOfNodes(root -> children[i]);
    }
    return sum;
}

int largestNodeData(TreeNode<int>* root, int maxi){
    maxi = max(maxi, root->data);
    // cout<<root->data<<" "<<maxi<<endl;
    for(int i=0; i<root->children.size(); i++){
        maxi = largestNodeData(root->children[i], maxi);
    }
    return maxi;
}

int heightOfTree(TreeNode<int>* root){
    if(!root)return 0;
    int val = 0;
    for(auto &i : root->children){
        val = max(val, heightOfTree(i));
    }
    return val + 1;
}

int countLeafNodes(TreeNode<int>* root, int cnt){
    if(root -> children.size()){
        for(int i = 0; i < root->children.size(); i++){
            cnt = countLeafNodes(root->children[i],cnt);
        }
    }else{
        cnt++;
        return cnt;
    }
    return cnt;
}

// another approach to count leaf nodes
// int countLeafNodes(TreeNode<int>* root, int cnt){
//     if(!root -> children.size()){
//         return 1;
//     }else{
//         for(int i = 0; i < root->children.size(); i++){
//             cnt += countLeafNodes(root->children[i],cnt);
//         }
//     }
//     return cnt;
// }

void preorder(TreeNode<int>* root){
    if(!root) return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root){
    if(!root) return;
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

void deleteRoot(TreeNode<int>* root){
    for(int i = 0 ; i<root -> children.size();i++){
        deleteRoot(root->children[i]);
    }
    delete root;
}

int countNodesGreaterThanX(TreeNode<int>* root, int x, int cnt){
    if(root -> data > x)cnt++;
    for(int i = 0 ; i<root -> children.size(); i++){
        cnt = countNodesGreaterThanX(root->children[i], x, cnt);
    }
    return cnt;
}

// here we are calculating the node having max immediate child sum, hence we will first calculate
// total sum of root & children and then call rec to calculate other sub children also and then in
// the end compare currSum with maxSum till now & update and return
void immediateChildSumHelper(TreeNode<int>* root, TreeNode<int>** resNode, int* maxSum){
    if(!root)return;

    int currSum = root -> data;
    for(int i = 0 ; i<root->children.size() ; i++){
        currSum += root->children[i]->data;
        immediateChildSumHelper(root->children[i], resNode, maxSum);
    }
    if(currSum > *maxSum){
        *resNode = root;
        *maxSum = currSum; 
    }

    return;
}
int immediateChildSum(TreeNode<int>* root){
    TreeNode<int>* resNode;
    int maxSum = 0;
    immediateChildSumHelper(root, &resNode , &maxSum);
    return resNode -> data;
}

int nextLargerThanX(TreeNode<int>* root,int x, int nextLarger){
    if(root -> data > x && (root -> data < nextLarger || nextLarger == 0)){
        nextLarger = root -> data;
    }
    for(int i = 0; i < root ->children.size(); i++){
        nextLarger = nextLargerThanX(root->children[i], x , nextLarger);
    }
    return nextLarger;
}

void secondLargestElementHelper(TreeNode<int>* root, TreeNode<int>** first, TreeNode<int>** second){

    if (root == NULL)return;

    if(!(*first)){
        *first = root;
    }
    else if((*first)->data < root->data){
        *second = *first;
        *first = root;
    }
    else if(!(*second)){
        if((*first)->data > root->data){
            *second = root;
        }
    }
    else if(root->data < (*first)->data && root->data > (*second)->data){
        *second = root;
    }

    for(int i = 0; i <root->children.size(); i++){
        secondLargestElementHelper(root->children[i], first, second);
    }
}
int secondLargestElement(TreeNode<int>* root){
    TreeNode<int>* first = NULL;
    TreeNode<int>* second = NULL;
    secondLargestElementHelper(root, &first, &second);
    return second -> data;
}

void replaceWithDepth(TreeNode<int>* root,int depth){
    root -> data = depth;
    for(int i = 0; i < root ->children.size(); i++){
        replaceWithDepth(root ->children[i], depth + 1);
    }
}


int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // root -> children.push_back(node1);
    // root -> children.push_back(node2);
    // printTree(root);


    // TreeNode<int>* root = takeInput();
    // printTree(root);


    TreeNode<int>* root = takeInputLevelWise();
    // printTree(root);
    printTreeLevelOrder(root);

    cout<<"Count of nodes: "<<countNodes(root)<<endl;

    cout<<"Sum of nodes values: "<<sumOfNodes(root)<<endl;

    cout<<"Largest data: "<<largestNodeData(root, INT_MIN)<<endl;

    cout<<"Height / Depth: "<<heightOfTree(root)<<endl;

    cout<<"No. of leaf nodes: "<<countLeafNodes(root, 0)<<endl;

    cout<<"Preorder: "<<endl;
    preorder(root);
    
    cout<<endl<<"Postorder: "<<endl;
    postorder(root);

    int x = 21;
    cout<<endl<<"No. of nodes greater than "<<x<<": "<<countNodesGreaterThanX(root, x , 0)<<endl;
    
    cout<<"Maximum immediate child sum: "<<immediateChildSum(root)<<endl;

    int xx = 35;
    cout<<"Next larger node than "<<xx<<": "<<nextLargerThanX(root, xx , 0)<<endl;

    cout<<"Second largest element in the tree: "<<secondLargestElement(root)<<endl;
    
    cout<<"Replace with Depth: "<<endl;
    replaceWithDepth(root, 0);
    printTreeLevelOrder(root);


    // deleteRoot(root);
    // or
    delete root;

    // to check deletion of root
    // cout<<endl<<"No. of leaf nodes: "<<countLeafNodes(root, 0)<<endl;

    return 0;
}


// trees input numbers

// 10
// 3
// 20
// 30
// 40
// 2
// 40
// 50
// 0
// 0
// 0
// 0


// 1
// 3
// 2
// 3
// 4
// 2
// 5
// 6
// 1
// 7
// 1
// 8
// 0
// 0
// 0
// 0

