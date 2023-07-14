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
class NodeValue{
     public:
     int maxvalue,minvalue,maxsize;
     NodeValue(int minvalue,int maxvalue,int maxsize){
        maxvalue=maxvalue;
        minvalue=minvalue;
        maxsize=maxsize;
     }
};
NodeValue BST(Node* root){
    if(!root){
        return NodeValue(INT_MIN,INT_MAX,0);
    }
    auto left=BST(root->left);
    auto right=BST(root->right);
    if(left.maxvalue<root->data && root->data<right.minvalue){
        return NodeValue(min(root->data,left.minvalue),max(root->data,right.maxvalue),left.maxsize+right.maxsize+1);
    }
    return NodeValue(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));

}
int largestBst(Node* root){
     return BST(root).maxsize;
}
int culculateNode(Node* root){
    if(!root) return 0;
    return 1+culculateNode(root->left)+culculateNode(root->right);
}
bool validateBst(Node* root,int minvalue,int maxvalue){
    if(!root) return true;
    if(root->data>minvalue && root->data<maxvalue){
       return validateBst(root->left,minvalue,root->data) && validateBst(root->right,root->data,maxvalue);
    }
    return false;
}
int largestSize(Node* root){
    if(!root) return 0;
    if(validateBst(root,INT_MIN,INT_MAX)){
       return culculateNode(root);
    }
    int left=largestSize(root->left);
    int right=largestSize(root->right);
    return max(left,right);
}
int main(){

}