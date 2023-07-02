#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
     Node(int data){
        data=data;
        left=NULL;
        right=NULL;
     }
};
int height(Node* root){
    if(!root) return 0;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return 1+max(leftheight,rightheight);
}
bool checkBBST(Node* root){
    if(!root) return true;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    if(abs(leftheight-rightheight)>1) return false;
    bool left=checkBBST(root->left);
    bool right=checkBBST(root->right);
    if(!left|| !right) return false;
    return true;
}
int BalanceHeight(Node* root){
    if(!root) return 0;
    int leftheight=BalanceHeight(root->left);
    int rightheight=BalanceHeight(root->right);
    if(leftheight==-1 || rightheight==-1) return -1;
    if(abs(leftheight-rightheight)>1) return -1;
    return 1+max(leftheight,rightheight);
}
int main(){

}