#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;

        while(headA!=NULL || headB!=NULL){
            if(headA){
                if(s.find(headA)!=s.end()) return headA;
                s.insert(headA);
                headA=headA->next;
            }
            if(headB){
                if(s.find(headB)!=s.end()) return headB;
                s.insert(headB);
                headB=headB->next;
            } 
        }

        return NULL;
    }
};

//optimal 1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;

        while(a!=b){
            if(a) a=a->next;
            else a=headB;

            if(b) b=b->next;
            else b=headA;
        }

        return a;
    }
};

//optimal 2 (optional)
//Calculate length of A and B. Move pointer of longest LL by lenA-lenB. Move both simultaneously till both are equal. 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;

        int lenA=0,lenB=0;
        while(a || b){
            if(a){
                lenA++;
                a=a->next;
            } 

            if(b){
                lenB++;
                b=b->next;
            }
        }

        a=headA;
        b=headB;

        if(lenA>lenB){
            for(int i=0;i<lenA-lenB;i++){
                a=a->next;
            }
        }
        else{
            for(int i=0;i<lenB-lenA;i++){
                b=b->next;
            }
        }

        while(a!=b){
            a=a->next;
            b=b->next;
        }

        return a;
    }
};

