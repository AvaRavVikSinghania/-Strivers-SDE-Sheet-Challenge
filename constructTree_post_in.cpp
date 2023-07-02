#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node * right;
    Node (int x){
        data=x;
        *left=NULL;
        *right=NULL;
    }
};
 Node *buildTreePostIn(vector<int>&inorder,int is,int ie,vector<int>&postorder,int ps,int pe,map<int,int>&hm){
  if(ps>pe||is>ie) return NULL;
    Node *root=new Node(postorder[pe]);
    int inroot=hm[postorder[pe]];
    int numsleft=inroot-is;
    root->left=buildTreePostIn(inorder,is,inroot-1,postorder,ps,ps+numsleft-1,hm);
    root->right=buildTreePostIn(inorder,inroot+1,ie,postorder,ps+numsleft+1,pe-1,hm);
    return root;
 }
Node *buildTree(vector<int>&inorder,vector<int>&postorder){
    if(inorder.size()!=postorder.size()) return NULL;
    map<int,int>hm;
    for(int i=0;i<inorder.size();i++){
        hm[inorder[i]]=i;
    }
     return buildTreePostIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hm);
}
int main(){

}