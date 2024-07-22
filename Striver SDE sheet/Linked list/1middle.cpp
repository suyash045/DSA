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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }

        temp=head;
        int mid=cnt/2;
        cnt=0;
        while(cnt!=mid){
            cnt++;
            temp=temp->next;
        }

        return temp;
    }
};
//TC is O(n)+O(n/2)

//Optimal
//two pointers slow and fast. Slow moves 1 at a time. Fast moves 2 at a time.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;

        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
};