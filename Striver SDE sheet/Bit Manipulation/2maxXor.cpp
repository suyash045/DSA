//get the max xor of two elements from array
#include<bits/stdc++.h>
using namespace std;

//Ex. Max Xor of 8 with arr elements
//Try to get opposite bits from left to right 
class Node{
    public:
    int bit;
    Node* children[2];
    
    Node(int b){
        bit=b;
        children[0]=NULL;
        children[1]=NULL;
    }
};
class Trie{
    public: 
    Node* root;
    Trie(){
        root=new Node(0);
    }

    void insert(int num){
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            Node* child;
            if(curr->children[bit]) child=curr->children[bit];
            else{
                child=new Node(bit);
                curr->children[bit]=child;
            }
            curr=child;
        }
        return;
    }

    int getMax(int num){
        int ans=0;
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=num>>i&1;
            Node* child;
            if(curr->children[!bit]){
                ans=(ans<<1)|(!bit);
                child=curr->children[!bit];
            }
            else{
                ans=(ans<<1)|(bit);
                child=curr->children[bit];
            }
            curr=child;
        }
        return ans^num;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t=new Trie();
        int n=nums.size();
        for(int i=0;i<n;i++){
            t->insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int temp=t->getMax(nums[i]);
            maxi=max(maxi,temp);
        }
        return maxi;
    }
};
//TC is O(n*32)+O(n*32);