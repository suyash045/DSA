#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    bool f(int n,int sum,vector<int>& nums,vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(n==0) return (nums[0]==sum);
        if(dp[n][sum]!=-1) return dp[n][sum];

        bool nottake=f(n-1,sum,nums,dp);
        bool take=false;
        if(nums[n]<=sum) take=f(n-1,sum-nums[n],nums,dp);

        return dp[n][sum]=take | nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int  i=0;i<n;i++) sum+=nums[i];
        
        if(sum%2==1) return false;

        vector<vector<int>> dp(n,vector<int> (sum/2+1,-1));
        return f(n-1,sum/2,nums,dp);
    }
};

//Tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int  i=0;i<n;i++) sum+=nums[i];
        
        if(sum%2==1) return false;

        vector<vector<bool>> dp(n,vector<bool> (sum/2+1,0));

        for(int i=0;i<n;i++) dp[i][0]=true;

        if(nums[0]<=sum/2) dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                bool nottake=dp[i-1][j];
                bool take=0;
                if(nums[i]<=j) take=dp[i-1][j-nums[i]];
                dp[i][j]=take|nottake;
            }
        }

        return dp[n-1][sum/2];
    }
};

//Space Optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int  i=0;i<n;i++) sum+=nums[i];
        
        if(sum%2==1) return false;

        vector<bool> curr(sum/2+1,0),prev(sum/2+1,0);

        prev[0]=curr[0]=true;

        if(nums[0]<=sum/2) prev[nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                bool nottake=prev[j];
                bool take=0;
                if(nums[i]<=j) take=prev[j-nums[i]];
                curr[j]=take|nottake;
            }
            prev=curr;
        }

        return prev[sum/2];
    }
};