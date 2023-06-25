#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
     if(!root) return {};
    queue<pair<BinaryTreeNode<int> *,int>>q;
    q.push({root,0});
    map<int,int>mp;
    while(!q.empty()){
      BinaryTreeNode<int> *curr=q.front().first;
        int line=q.front().second;
        q.pop();
        mp[line]=curr->data;
        if(curr->left){
            q.push({curr->left,line-1});
        }
        if(curr->right){
            q.push({curr->right,line+1});
        }
    }
    vector<int>ans;
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}
