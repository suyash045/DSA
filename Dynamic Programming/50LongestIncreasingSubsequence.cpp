#include<bits/stdc++.h>
using namespace std;


//optimal
//here dp[i] stores length of LIS upto ith index
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(dp[i],ans);
        }

        return ans;
    }
};
//TC is O(n^2)
//SC is O(n)

//Below soln are optional

//Memoization
class Solution {
public:
    int f(int i,int prev,vector<int>& nums,int n, vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=0) return dp[i][prev+1];

        int nottake=f(i+1,prev,nums,n,dp);
        int take=0;
        if(prev==-1 || nums[i]>nums[prev]) take=1+f(i+1,i,nums,n,dp);

        return dp[i][prev+1]=max(nottake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        return f(0,-1,nums,n,dp);
    }
};

//Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int nottake=dp[i+1][j+1];
                int take=0;
                if(j==-1 || nums[i]>nums[j]) take=1+dp[i+1][i+1];

                dp[i][j+1]=max(nottake,take);
            }
        }

        return dp[0][0];
    }
};

//Space Optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1,0),curr(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int nottake=next[j+1];
                int take=0;
                if(j==-1 || nums[i]>nums[j]) take=1+next[i+1];

                curr[j+1]=max(nottake,take);
            }
            next=curr;
        }

        return curr[0];
    }
};

