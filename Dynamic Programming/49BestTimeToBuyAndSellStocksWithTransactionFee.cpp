#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int f(int i,int buy,vector<int>& prices,int n, vector<vector<int>> &dp,int fee){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy){
            return dp[i][buy]=max(-prices[i]-fee+f(i+1,0,prices,n,dp,fee),f(i+1,1,prices,n,dp,fee));
        }else{
            return dp[i][buy]=max(prices[i]+f(i,1,prices,n,dp,fee),f(i+1,0,prices,n,dp,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return f(0,1,prices,n,dp,fee);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        for(int i=n-1;i>=0;i--){
            dp[i][1]=max(-prices[i]-fee+dp[i+1][0],dp[i+1][1]);
            dp[i][0]=max(prices[i]+dp[i][1],dp[i+1][0]);
        }
        return dp[0][1];
    }
};

//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> curr(2,0),next(2,0);
        for(int i=n-1;i>=0;i--){
            curr[1]=max(-prices[i]-fee+next[0],next[1]);
            curr[0]=max(prices[i]+curr[1],next[0]);

            next=curr;
        }
        return curr[1];
    }
};