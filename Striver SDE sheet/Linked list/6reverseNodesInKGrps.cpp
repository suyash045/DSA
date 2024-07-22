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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start=new ListNode(0);
        start->next=head;
        ListNode* pre=start;
        ListNode* curr=start;
        ListNode* nex=start;

        //For counting total nodes
        int count=0;
        while(curr->next!=NULL){
            count++;
            curr=curr->next;
        }
        curr=start;

        while(count>=k){
            curr=pre->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            } 
            count-=k;
            pre=curr;
        }

        return start->next;
    }
};