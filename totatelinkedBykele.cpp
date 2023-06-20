/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *root, int k) {
     // Write your code here.
     if(!root||!root->next||k==0) return root;
     Node*curr=root;
     int len=1;
     while(curr->next && ++len){
          curr=curr->next;
     }
     //converting it to circular linked list
     curr->next=root;
     k=k%len;
     k=len-k;
     while(k--){
          curr=curr->next;
     }
     root=curr->next;
     curr->next=NULL;
     return root;
}