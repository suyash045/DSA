//We can hold only one day
#include<bits/stdc++.h>
using namespace std;

//optimal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int lastSell=-1;
        int total=0;
        for(int i=1;i<n;i++){
            if(i-2>=0 && lastSell<=i-2) mini=min(prices[i-1],prices[i-2]);
            else if(lastSell==i-1) mini=prices[i-1];

            if(mini<prices[i]){
                int profit=prices[i]-mini;
                lastSell=i;
                total+=profit;
            }
        }
        return total;
    }
};

//Below code may not for this question
//Memoization
class Solution {
public:
    int f(int i,int buy,int n,vector<int>& prices,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(i==n-1){
            if(buy) return dp[i][buy]=0;
            else return dp[i][buy]=prices[n-1];
        } 
        if(dp[i][buy]!=0) return dp[i][buy];

        if(buy){
            return dp[i][buy]=max(-prices[i]+f(i+1,0,n,prices,dp),f(i+1,1,n,prices,dp));
        }else{
            return dp[i][buy]=max(prices[i]+f(i,1,n,prices,dp),prices[i+1]+f(i+1,1,n,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,0));
        return f(0,1,n,prices,dp);
    }
};

//Tabulation


//Space Optimization

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int lastSell=-1;
        int total=0;
        for(int i=1;i<n;i++){
            if(i-2>=0 && lastSell<=i-2) mini=min(prices[i-1],prices[i-2]);
            else if(lastSell==i-1) mini=prices[i-1];

            if(mini<prices[i]){
                int profit=prices[i]-mini;
                lastSell=i;
                total+=profit;
            }
        }
        return total;
    }
};