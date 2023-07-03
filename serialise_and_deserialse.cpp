#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        data=data;
        left=NULL;
        right=NULL;
    }
};//morries traversal
string serialzable(Node *root){
    if(!root) return "";
    string s="";
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL) s.append("#,");
        else{
            s.append(to_string(root->data)+',');
        }
        if(curr!=NULL){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}
Node* deserializable(string data){
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
     getline(s,str,',');
     Node* root=new Node(stoi(str));
     queue<Node*>q;
     q.push(root);
     while(!q.empty()){
        Node* node=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            node->left=NULL;
        }else{
            Node* leftNode=new Node(stoi(str));
            node->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#"){
            node->right=NULL;
        }else{
            Node* rightNode=new Node(stoi(str));
            node->left=rightNode;
            q.push(rightNode);
        }
     }
     return root;
}
int main(){

}