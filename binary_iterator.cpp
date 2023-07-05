#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        *left=NULL;
        *right=NULL;
    }

};
//inorder traversal is next approach for this problem
class BSTIterator{
private: stack<Node*>mystack;
public:
BSTIterator(Node *root){
    pushAll(root);
}
bool hasnext(){
    return !mystack.empty();
}
int next(){
    Node *temp=mystack.top();
    mystack.pop();
    pushAll(temp->right);
    return temp->data;
}
private:
 void pushAll(Node *root){
    for(;root!=NULL;mystack.push(root),root=root->left);
 }
};
int main(){

}