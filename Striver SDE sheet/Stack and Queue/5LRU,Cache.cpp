//code not working
#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int key,int val){
            key=key;
            val=val;
            next=NULL;
            prev=NULL;
        }
    };

    int cap;
    unordered_map<int,node*> m;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(node* temp){
        temp->next=head->next;
        temp->prev=head;
        head->next=temp;
        temp->next->prev=temp;
    }

    void deleteNode(node* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* n=m[key];
            int ans=n->val;
            m.erase(key);
            deleteNode(n);
            addNode(n);
            m[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* temp=m[key];
            deleteNode(temp);
            m.erase(key);
        }
        if(m.size()>=cap){
            deleteNode(tail->prev);
            m.erase(tail->prev->key);
        }

        node* n=new node(key,value);
        addNode(n);
        m[key]=head->next;
    }   
};

