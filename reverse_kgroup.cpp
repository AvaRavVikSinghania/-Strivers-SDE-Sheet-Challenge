#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
       int data;
       Node* next;
       Node(int data){
        this->data=data;
        next=NULL;
      }
};
Node* reverse(Node* head,int k){
    if(!head|| k<=1) return head;
    Node* curr=head;
    int count=0;
    while(head){
        count++;
        curr=curr->next;
    }
    Node* dummy=new Node(0);
    dummy->next=head;
    Node*prev=dummy,*nex=dummy,*curr=dummy;
    while(count>=k){
        curr=prev->next;
        nex=curr->next;
        for(int i=1;i<k;i++){
            curr->next=nex->next;
            nex->next=prev->next;
            prev->next=nex;
            nex=curr->next;
        }
        prev=curr;
        count-=k;
    }
    return dummy->next;
}

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
int LinkedListLength(Node *head){
	int count=0;
	while(head){
		++count;
		head = head->next;
	}
	return count;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head==NULL || head->next==NULL) return head;

	int length = LinkedListLength(head);

	Node *dummy = new Node(0);
	dummy->next = head;
	Node *prev = dummy;
	Node *curr,*nex;
	int i=0;

	while(length>0 && i<n){
		if(b[i]==0){
			i++;
			continue;
		};
		curr = prev->next;
		nex = curr->next;

			if(length>=b[i]){
				for(int j=1;j<b[i];j++){
				curr->next = nex->next;
				nex->next = prev->next;
				prev->next = nex;
				nex = curr->next;
			    }

				prev = curr;
				length-=b[i];
				i++;
			}

			else if(length<b[i]){
				for(int j=1;j<length;j++){
				curr->next = nex->next;
				nex->next = prev->next;
				prev->next = nex;
				nex = curr->next;
			    }

				prev = curr;
				length-=b[i];
				i++;
			}
			
		}

		return dummy->next;
}
int main(){

}