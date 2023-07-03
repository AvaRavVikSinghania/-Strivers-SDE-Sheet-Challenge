#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int val){
    data=val;
    *left=NULL;
    *right=NULL;
}
};
Node* build(vector<int>&preorder,int &i,int bound){
    if(i==preorder.size()|| preorder[i]>bound) return NULL;
    Node* root=new Node(preorder[i]++);
    root->left=build(preorder,i,root->data);

}
Node* BSTfromPreorder(vector<int>&preorder){
    int i=0;
    return build(preorder,i,INT_MAX);
}
int main(){

}