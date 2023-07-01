#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode< int >*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        BinaryTreeNode< int >*prev;
        for(int i=0;i<n;i++){
           BinaryTreeNode< int >*curr=q.front();
           q.pop();
            if(curr->left){
               q.push(curr->left);
           }
           if(curr->right){
               q.push(curr->right);
           }
           if(i==0){
               prev=curr;
           }else{
               prev->next=curr;
               prev=curr;
           }
        }
    }
    return ;
}