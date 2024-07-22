#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int solve(int n,vector<int>& nums,vector<int> &dp){
        if(n==0) return dp[0]=nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1){
            return dp[n];
        }

        int pick=nums[n]+solve(n-2,nums,dp);
        int unpick=solve(n-1,nums,dp);
        return dp[n]=max(pick,unpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
    }
};

//Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick;

            if(i>1) pick=nums[i]+dp[i-2];
            else pick=nums[i];
            int unpick=dp[i-1];

            dp[i]=max(pick,unpick);
        }

        return dp[n-1];
    }
};

//Space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            int pick=nums[i]+prev2;
            int unpick=prev1;

            int curr=max(pick,unpick);
            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};