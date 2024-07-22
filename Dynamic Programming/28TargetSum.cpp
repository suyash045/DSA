#include<bits/stdc++.h>
using namespace std;

//Memoization
//We can say there are two groups(+ve and -ve). targetSum = difference between two groups.
//x-y=d and x+y=sum
//x=(sum-d)/2
class Solution {
public:
    int f(int n,vector<int>& nums,int target,vector<vector<int>> &dp){
        if(n==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || target==nums[0]) return 1;
            return 0;
        }

        int nottake=f(n-1,nums,target,dp);
        int take=0;
        if(nums[n]<=target) take=f(n-1,nums,target-nums[n],dp);

        return nottake+take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        if(target<0) target=-target;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];

        if(sum<target || (sum-target)%2!=0) return 0;

        return f(n-1,nums,(sum-target)/2,dp);
    }
};