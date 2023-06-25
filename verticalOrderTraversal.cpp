#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    queue<pair<TreeNode<int> *,int>>q;
    q.push({root,0});
    vector<int>ans;
    map<int,vector<int>>mp;
    while(!q.empty()){
        TreeNode<int> *curr=q.front().first;
        int line=q.front().second;
        q.pop();
        mp[line].push_back(curr->data);
        if(curr->left){
            q.push({curr->left,line-1});
        }
        if(curr->right){
            q.push({curr->right,line+1});
        }
    }
    for(auto it:mp){
        for(auto a:it.second){
            ans.push_back(a);
        }
    }
    return ans;
}