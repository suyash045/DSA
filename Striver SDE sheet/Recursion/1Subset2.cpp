#include<bits/stdc++.h>
using namespace std;

//Normal code 
class Solution {
public:
    void f(int n,vector<int>& nums,set<vector<int>> &ans,vector<int> temp){
        if(n<0){
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }

        f(n-1,nums,ans,temp);
        
        temp.push_back(nums[n]);
        f(n-1,nums,ans,temp);

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> ans;
        vector<int> temp;
        f(n-1,nums,ans,temp);
        vector<vector<int>> ans1(ans.begin(),ans.end());
        return ans1;
    }
};

//We can avoid duplicates without using set
class Solution {
public:
    void f(int ind,vector<int>& nums,vector<vector<int>> &ans,vector<int> temp){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            
            temp.push_back(nums[i]);
            f(i+1,nums,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        f(0,nums,ans,temp);
        return ans;
    }
};