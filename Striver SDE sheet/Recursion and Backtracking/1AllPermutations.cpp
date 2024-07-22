#include<bits/stdc++.h>
using namespace std;

//Storing freq
class Solution {
public:
    void f(vector<int>& nums,vector<int> temp,vector<vector<int>> &ans,vector<int> freq){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(freq[i]) continue;
            temp.push_back(nums[i]);
            freq[i]=1;
            f(nums,temp,ans,freq);
            freq[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(n,0);

        f(nums,temp,ans,freq);
        return ans;
    }
};

//Swaping
class Solution {
public:
    void f(int ind,vector<int>& nums,vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            f(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;

        f(0,nums,ans);
        return ans;
    }
};
