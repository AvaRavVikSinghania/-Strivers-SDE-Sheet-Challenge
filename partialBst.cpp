#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool check(BinaryTreeNode<int> *root,int low,int high){
     if(!root) return true;
     if(root->data<low || root->data>high) return false;
     return check(root->left,low,root->data) && check(root->right,root->data,high);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root) return true;
    return check(root,INT_MIN,INT_MAX);
}