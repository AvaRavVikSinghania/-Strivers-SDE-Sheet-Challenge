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
 TreeNode<int> *findLca(TreeNode<int> *root, int x, int y){
    if(!root) return NULL;
    if(root->data==x|| root->data==y) return root;
    TreeNode<int> *left=findLca(root->left,x,y);
    TreeNode<int> *right=findLca(root->right,x,y);
    if(left && right){
        return root;
    }
    if(!left) return right;
     return left;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    return findLca(root,x,y)->data;
}