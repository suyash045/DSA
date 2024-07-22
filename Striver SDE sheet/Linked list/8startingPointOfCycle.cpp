#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//We can do hashing

//
//Find collision point. dist from collision = dist from start
//Proof: Let's say slow pointer moved = l1+l2, fast pointer moved = l1+l2+nC
//l1+l2=2(l1+l2+nC)
//l1=l2-nC
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }

        if(fast==NULL || fast->next==NULL) return NULL;

        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }

        return slow;
    }
};