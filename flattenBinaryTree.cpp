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
Node *previ=NULL;
void flatten(Node* root){
    if(root==NULL) return ;
    flatten(root->left);
    flatten(root->right);
    root->right = previ;
    root->left=NULL;
    previ=root;
}
void flatten2(Node* root){
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node* curr=st.top();
        st.pop();
        if(curr->right){
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }
        if(!st.empty()){
            curr->right=st.top();
        }
        curr->left=NULL;
    }
}
int main(){

}