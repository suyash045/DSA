//queries[i] = [xi, mi].
//get the max xor of xi and array element where array element < mi.
#include<bits/stdc++.h>
using namespace std;

//Arrange queries and array in sorted order. Add only element which are less than given number in trie.
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> offQ;//offline Queries
        int m=queries.size();
        for(int i=0;i<m;i++){
            offQ.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(offQ.begin(),offQ.end());

        int k=0;
        Trie* t=new Trie();
        vector<int> ans(m,-1);
        bool notEmpty=0;
        for(int i=0;i<m;i++){
            while(k<n && nums[k]<=offQ[i].first){
                notEmpty=1;
                t->insert(nums[k]);
                k++;
            }
            if(notEmpty) ans[offQ[i].second.second]=t->getMax(offQ[i].second.first);
        }
        return ans;
    }
};