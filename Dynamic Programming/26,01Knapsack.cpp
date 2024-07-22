#include<bits/stdc++.h>
using namespace std;
//For normal recursion TC is O(2^n) and SC is O(n)

//Memoization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int n, int wt[], int val[],int W,vector<vector<int>> &dp){
        if(n==0){
            if(wt[0]<=W) return val[0];
            return 0;
        };
        if(dp[n][W]!=-1) return dp[n][W];
        
        int notpick=f(n-1,wt,val,W,dp);
        int pick=0;
        if(wt[n]<=W) pick=val[n]+f(n-1,wt,val,W-wt[n],dp);
        
        return dp[n][W]=max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    {   
        vector<vector<int>> dp(n,vector<int> (W+1,-1));
        return f(n-1,wt,val,W,dp);
    }
};
//TC is O(n*W)
//SC is O(n*W)+O(n*W)

//Tabulation
//DP array:
//Ex. val[]={1,2,3}
//    wt[]={4,5,1}
//    0 1 2 3 4 
//
// 0  0 0 0 0 1
// 1  0 0 0 0 1
// 2  0 3 3 3 3 
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {   
        vector<vector<int>> dp(n,vector<int> (W+1,0));
        for(int w=wt[0];w<=W;w++) dp[0][w]=val[0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int notpick=dp[i-1][j];
                int pick=0;
                if(wt[i]<=j) pick=val[i]+dp[i-1][j-wt[i]];
                dp[i][j]=max(pick,notpick);
            }
        }
        
        return dp[n-1][W];
    }
};
//TC is O(n*W)
//SC is O(n*W)

//Space Optimization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {   
        vector<int> prev(W+1,0),curr(W+1,0);
        for(int w=wt[0];w<=W;w++) curr[w]=prev[w]=val[0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int notpick=prev[j];
                int pick=0;
                if(wt[i]<=j) pick=val[i]+prev[j-wt[i]];
                curr[j]=max(pick,notpick);
            }
            prev=curr;
        }
        
        return curr[W];
    }
};
//TC is O(n*W)
//SC is O(W)

//We can do space optimization by using only prev.
//If we traverse from W to w[0] we only requires left values 
// in prev so we can directly make changes in prev vector.

//Further Space Optimization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {   
        vector<int> prev(W+1,0);
        for(int w=wt[0];w<=W;w++) prev[w]=val[0];
        
        for(int i=1;i<n;i++){
            for(int j=W;j>=0;j--){
                int notpick=prev[j];
                int pick=0;
                if(wt[i]<=j) pick=val[i]+prev[j-wt[i]];
                prev[j]=max(pick,notpick);
            }
        }
        
        return prev[W];
    }
};
