#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(!root) return {};
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    map<int,int>mp;
    while(!q.empty()){
        TreeNode<int> *curr=q.front().first;
        int line=q.front().second;
        q.pop();
        if(mp.find(line)==mp.end()){
            mp[line]=curr->val;
        }
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