#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
};
bool isleaf(Node *root){
    if(root->left==NULL && root->right==NULL) return true;
     return false;
}
void addleftBoundary(Node*root,vector<int>&res){
   Node *curr=root->left;
   while(curr){
    if(!isleaf(curr)) res.push_back(curr->data);
    if(curr->left) curr=curr->left;
    else{
        curr=curr->right;
    }
   }
}
void addrightBoundary(Node * root,vector<int>&res){
   Node* curr=root->right;
   vector<int>temp;
   while(curr){
    if(!isleaf(curr)) temp.push_back(curr->data);
    if(curr->right) curr=curr->right;
    else{
        curr=curr->left;
    }
   }
   for(int i=temp.size()-1;i>=0;i--){
    res.push_back(temp[i]);
   }
}
void addleaves(Node *root,vector<int>&res){
    if(isleaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addleaves(root->left,res);
    if(root->right) addleaves(root->right,res);
}
vector<int>printboundary(Node *root){
    vector<int>res;
    if(root==NULL){
        return res;
    }
    if(!isleaf(root)) res.push_back(root->data);
    addleftBoundary(root,res);
    addleaves(root,res);
    addrightBoundary(root,res);
    return res;
}
int main(){
    return 0;
}