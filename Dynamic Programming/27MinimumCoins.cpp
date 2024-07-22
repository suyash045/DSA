#include<bits/stdc++.h>
using namespace std;
//If que included infinite supply or multiple use then while taking do f(n,...)

//Memoization
class Solution {
public:
    int f(int n,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(amount==0) return 0;
        if(n<0) return 1e5;
        if(n==0){
            if(amount%coins[n]==0) return amount/coins[0];
            return 1e5;
        }
        if(dp[n][amount]!=0) return dp[n][amount];
        
        int nottake=f(n-1,amount,coins,dp);
        int take=1e5;
        if(coins[n]<=amount) take=1+f(n,amount-coins[n],coins,dp);

        return dp[n][amount]=min(nottake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        int ans=f(n-1,amount,coins,dp);
        if(ans==1e5) return -1 ;
        return ans;
    }
};

//Tabulation
//DP array:
//coins = [1,2,5], amount = 11
//     0 1 2 3 4 5 6 7 8 9 10 11
//1 0  0 1 2 3 4 5 6 7 8 9 10 11
//2 1  0 1 1 2 2 3 3 4 4 5 5  6
//5 2  0 1 1 2 2 1 2 2 3 3 2  3
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0) dp[0][T]=T/coins[0];
            else dp[0][T]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake=dp[i-1][j];
                int take=1e9;
                if(coins[i]<=j) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,nottake);
            }
        }

        int ans=dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};

//Space Optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        vector<int> curr(amount+1,0),prev(amount+1,0);
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0) prev[T]=curr[T]=T/coins[0];
            else prev[T]=curr[T]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake=prev[j];
                int take=1e9;
                if(coins[i]<=j) take=1+curr[j-coins[i]];
                curr[j]=min(take,nottake);
            }
            prev=curr;
        }

        int ans=prev[amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};
