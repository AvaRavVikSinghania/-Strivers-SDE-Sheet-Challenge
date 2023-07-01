#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
TreeNode<int>*build(int low,int high,vector<int>&arr){
    if(low>high) return NULL;
    int mid=(low+high)/2;
    TreeNode<int>*root= new TreeNode<int>(arr[mid]);
    root->right=build(mid+1,high,arr);
    root->left=build(low,mid-1,arr);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    int low=0;
    int high=arr.size()-1;
    return build(0,high,arr);
}