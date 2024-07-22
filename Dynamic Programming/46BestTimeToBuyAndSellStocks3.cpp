#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int f(int i,int buy,int count,vector<int>& prices,int n, vector<vector<vector<int>>> &dp){
        if(i==n || count==2) return 0;
        if(dp[i][buy][count]!=0) return dp[i][buy][count];

        if(buy){
            return dp[i][buy][count]=max(-prices[i]+f(i+1,0,count,prices,n,dp),f(i+1,1,count,prices,n,dp));
        }else{
            return dp[i][buy][count]=max(prices[i]+f(i,1,count+1,prices,n,dp),f(i+1,0,count,prices,n,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,0)));
        return f(0,1,0,prices,n,dp);
    }
};
//TC is O(n*2*3)
//TC is O(n)+O(n*2*3)

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count>=0;count--){
                    if(buy) dp[i][buy][count]=max(-prices[i]+dp[i+1][0][count],dp[i+1][1][count]);
                    else dp[i][buy][count]=max(prices[i]+dp[i+1][1][count+1],dp[i+1][0][count]);
                }
            }
        }
        return dp[0][1][0];
    }
};
//Instead of using n*2*3 matrix we can also use n*4 matrix, where column indices are transcaction no.
//Transaction no.
// 0 1 2 3
// B S B S 
//For even transaction no. we can buy

//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> next(2,vector<int> (3,0)),curr(2,vector<int> (3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count>=0;count--){
                    if(buy) curr[buy][count]=max(-prices[i]+next[0][count],next[1][count]);
                    else curr[buy][count]=max(prices[i]+next[1][count+1],next[0][count]);
                }
            }
            next=curr;
        }
        return curr[1][0];
    }
};


