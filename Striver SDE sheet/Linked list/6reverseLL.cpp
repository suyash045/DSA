#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* start=new ListNode(0);
        start->next=head;
        ListNode* pre=start;
        ListNode* curr=start;
        ListNode* nex=start;

        curr=pre->next;
        nex=curr->next;
        while(nex){
            curr->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=curr->next;
        }
        return start->next;
    }
};