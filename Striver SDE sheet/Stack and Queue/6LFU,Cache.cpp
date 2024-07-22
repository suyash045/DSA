#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int key,val,cnt;
    node* next;
    node* prev;

    node(int _key,int _val){
        key=_key;
        val=_val;
        cnt=1;
        next=NULL;
        prev=NULL;
    }
};

class List{
    public:
    int size;
    node* head;
    node* tail;
    List(){
        head=new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void addFront(node* Node){
        node* temp=head->next;
        Node->next=temp;
        temp->prev=Node;
        head->next=Node;
        Node->prev=head;
        size++;
    }

    void removeNode(node* Node){
        node* preNode=Node->prev;
        node* nexNode=Node->next;
        preNode->next=nexNode;
        nexNode->prev=preNode;
        size--;
    }

};

class LFUCache {
public:

    map<int,node*> keyNode;
    map<int,List*> freq; 
    int maxSize,size,minFreq;

    LFUCache(int capacity) {
        maxSize=capacity;
        size=0;
        minFreq=0;
    }

    void updateFreq(node* Node){
        keyNode.erase(Node->key);
        freq[Node->cnt]->removeNode(Node);
        if(Node->cnt==minFreq && freq[Node->cnt]->size==0){
            minFreq++;
        }

        List* nextHighFreq=new List();
        if(freq.find(Node->cnt+1)!=freq.end()){
            nextHighFreq=freq[Node->cnt+1];
        }
        Node->cnt+=1;
        nextHighFreq->addFront(Node);
        freq[Node->cnt]=nextHighFreq;
        keyNode[Node->key]=Node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            node* temp=keyNode[key];
            int ans=temp->val;
            updateFreq(temp);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize==0) return;

        if(keyNode.find(key)!=keyNode.end()){
            node* Node=keyNode[key];
            Node->val=value;
            updateFreq(Node);
        }
        else{
            if(size==maxSize){
                List* list=freq[minFreq];
                keyNode.erase(list->tail->prev->key);
                size--;
            }
            size++;
            minFreq=1;
            List* listFreq=new List();
            if(freq.find(minFreq)!=freq.end()){
                listFreq=freq[minFreq];
            }
            node* Node=new node(key,value);
            listFreq->addFront(Node);
            keyNode[key]=Node;
            freq[minFreq]=listFreq;   
        }
    }
};

