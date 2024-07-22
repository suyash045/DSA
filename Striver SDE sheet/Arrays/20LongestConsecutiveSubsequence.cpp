#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int count=0;
        int maxi=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) continue;
            if(nums[i]==nums[i+1]-1) count++;
            else count=0;
            maxi=max(maxi,count);
        }
        return maxi+1;
    }
};

//But in leetcode this shows more runtime and space
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }

        int maxi=0;
        for(auto i:s){
            if(s.find(i-1)==s.end()){
                int cnt=1;
                int x=i;

                while(s.find(x+1)!=s.end()){
                    cnt++;
                    x++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};