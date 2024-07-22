#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int f(int n,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(amount==0) return dp[n][amount]=1;
        if(n==0){
            if(amount%coins[0]==0) return dp[n][amount]=1;
            return dp[n][amount]=0;
        }
        if(dp[n][amount]!=0) return dp[n][amount]; 

        int nottake=f(n-1,amount,coins,dp);
        int take=0;
        if(coins[n]<=amount) take=f(n,amount-coins[n],coins,dp);

        return dp[n][amount]=nottake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        return f(n-1,amount,coins,dp);
    }
};

//Tabulation
//DP array:
//amount = 5, coins = [1,2,5]
//     0 1 2 3 4 5 
//1 0  1 1 1 1 1 1
//2 1  1 1 2 2 3 3 
//5 2  1 1 2 2 3 4 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));

        for(int i=0;i<=amount;i++) dp[0][i]=(i%coins[0]==0);

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(coins[i]<=j) take=dp[i][j-coins[i]];
                dp[i][j]=take+nottake;
            }
        }

        return dp[n-1][amount];
    }
};

//Space Optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);

        for(int i=0;i<=amount;i++) prev[i]=curr[i]=(i%coins[0]==0);

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake=prev[j];
                int take=0;
                if(coins[i]<=j) take=curr[j-coins[i]];
                curr[j]=take+nottake;
            }
            prev=curr;
        }

        return curr[amount];
    }
};