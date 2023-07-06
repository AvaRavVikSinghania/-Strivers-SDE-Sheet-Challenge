#include<bits/stdc++.h>
using namespace std;
class Node{
     public:
     int data;
     Node* next;
     Node* random;
     Node(int data){
        this->data=data;
        next=NULL;
        random=NULL;
     }
};
Node* copyLinkedList(Node* head){
    Node* temp=head;
    map<Node*,Node*>mp;
    while(temp!=NULL){
        Node* copy=new Node(temp->data);
        mp[temp]=copy;
        temp=temp->next;
    }
    temp=head;
    while(temp){
        mp[temp]->next=mp[temp->next];
        mp[temp]->random=mp[temp->random];
        temp=temp->next;
    }
   return mp[head];  
}
int main(){

}