#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   int val;
   list<Node*>neighbour;
   Node(int val){
    val=val;
    neighbour={NULL};
   }
};
unordered_map<Node*,Node*>mp;
void dfs(Node*node ,Node* clonenode){
    for(Node*n:node->neighbour){
        if(mp.find(n)==mp.end()){
            Node* newClone=new Node(n->val);
            mp[n]=newClone;
            clonenode->neighbour.push_back(newClone);
            dfs(n,newClone);
        }
        else {
            clonenode->neighbour.push_back(mp[n]);
        }
    }
}
Node* clone(Node* node){
    if(node==NULL) return NULL;
    Node* cloneNode=new Node(node->val);
    mp[node]=cloneNode;
    dfs(node,cloneNode);
    return cloneNode;
}
int main(){

}