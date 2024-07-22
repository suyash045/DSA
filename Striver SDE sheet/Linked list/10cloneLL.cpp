#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//use hashing
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node* temp=head;
        Node* newHead=NULL;
        while(temp!=NULL){
            Node* newNode=new Node(temp->val);
            if(temp==head) newHead=newNode;
            m[temp]=newNode;
            temp=temp->next;
        }

        for(auto i:m){
            if(i.first->next) i.second->next=m[i.first->next];
            if(i.first->random) i.second->random=m[i.first->random];
        }
        return newHead;
    }
};
//TC is O(n)+O(n)
//SC is O(n)

//Optimal 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp=head;
        while(temp!=NULL){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }

        temp=head;
        while(temp!=NULL){
            if(temp->random) temp->next->random=temp->random->next;
            temp=temp->next->next;
        }

        temp=head;
        Node* front=temp->next->next;
        Node* newHead=temp->next;
        while(front!=NULL){
            temp->next->next=front->next;
            temp->next=front;
            temp=front;
            front=front->next->next;
        }
        temp->next=NULL;

        return newHead;
    }
};
//TC is O(n)+O(n)+O(n) = O(n)
//SC is O(1)
