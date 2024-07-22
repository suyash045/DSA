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
    bool isPalindrome(ListNode* head) {
        ListNode* curr=head;
        int n=0;
        while(curr!=NULL){
            n++;
            curr=curr->next;
        }

        curr=head;
        int i=0;
        stack<int> st;
        while(i<n/2){
            st.push(curr->val);
            curr=curr->next;
            i++;
        }

        if(n%2==1) curr=curr->next;

        while(curr!=NULL){
            if(curr->val!=st.top()) return false;
            st.pop();
            curr=curr->next;
        }

        return true;
    }
};

//Optimal
//Find middle element using slow and fast pointers. Reverse LL from mid to last. By using two pointers check elements are same or not.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL || head==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* pre=slow;
        ListNode* curr=slow->next;
        ListNode* nex=curr->next;

        while(curr->next!=NULL){
            curr->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=curr->next;
        }

        slow=head;
        fast=pre->next;    
        while(fast!=NULL){
            if(slow->val != fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }   
        return true; 
    }
};
