#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void inorder(TreeNode<int> *root, map<int,int>&mp,int level){
    if(!root) return ;
    if(mp.find(level)==mp.end()){
        mp[level]=root->data;
    }
    inorder(root->left,mp,level+1);
    inorder(root->right,mp,level+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    map<int,int>ans;
    inorder(root,ans,0);
    vector<int>a;
    for(auto it:ans){
        a.push_back(it.second);
    }
    return a;
}