#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int maxsum(TreeNode<int> *root,long long int &maxi){
    if(root==NULL) return -1;
    if(root->left==NULL && root->right==NULL){
        return root->val;
    }
    long long int left=maxsum(root->left,maxi);
    long long int right=maxsum(root->right,maxi);
    if(root->left!=NULL && root->right!=NULL){
        maxi=max(maxi,left+right+root->val);
        return max(left,right)+root->val;
    }
    else if(root->left==NULL){
        return right+root->val;
    }
    return left+root->val;
    
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long int maxi=-1;
    maxsum(root,maxi);
    return maxi;
}