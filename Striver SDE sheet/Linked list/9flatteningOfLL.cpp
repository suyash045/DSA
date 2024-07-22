#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

//Apply Brute force 
Node *merge(Node* A, Node* B){
    Node* newHead=NULL;
    Node* temp=NULL;
    
    if(A->data < B->data){
        newHead=A;
        A=A->bottom;
    }
    else{
        newHead=B;
        B=B->bottom;
    }
    
    temp=newHead;
    
    while(A!=NULL && B!=NULL){
        if(A->data < B->data){
            temp->bottom=A;
            temp=temp->bottom;
            A=A->bottom;
        }
        else{
            temp->bottom=B;
            temp=temp->bottom;
            B=B->bottom;
        }
    }
    
    if(A) temp->bottom=A;
    if(B) temp->bottom=B;
    
    return newHead;
}
Node *flatten(Node *root){
   if(root==NULL || root->next==NULL) return root;
   
   root->next=flatten(root->next);
   
   root=merge(root,root->next);
   
   return root;
}