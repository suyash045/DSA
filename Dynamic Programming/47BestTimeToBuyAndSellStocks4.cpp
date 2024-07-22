#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int f(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size() || k==0) return dp[i][buy][k]=0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];     

        if(buy) return dp[i][buy][k]=max(-prices[i]+f(i+1,0,k,prices,dp),f(i+1,1,k,prices,dp));
        else return dp[i][buy][k]=max(prices[i]+f(i,1,k-1,prices,dp),f(i+1,0,k,prices,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return f(0,1,k,prices,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int j=1;j<=k;j++){
                    if(buy) dp[i][buy][j]=max(-prices[i]+dp[i+1][0][j],dp[i+1][1][j]);
                    else dp[i][buy][j]=max(prices[i]+dp[i+1][1][j-1],dp[i+1][0][j]);
                }
            }
        }

        return dp[0][1][k];
    }
};

//Space Optimization
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> next(2,vector<int> (k+1,0)),curr(2,vector<int> (k+1,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int j=1;j<=k;j++){
                    if(buy) curr[buy][j]=max(-prices[i]+next[0][j],next[1][j]);
                    else curr[buy][j]=max(prices[i]+next[1][j-1],next[0][j]);
                }
            }
            next=curr;
        }

        return curr[1][k];
    }
};