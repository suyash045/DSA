//Total profit we can make
#include<bits/stdc++.h>
using namespace std;

//optimal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cost=prices[0];
        int total=0;
        for(int i=1;i<n;i++){
            cost=prices[i-1];

            if(cost<prices[i]){
                int profit=prices[i]-cost;
                total+=profit;
            }
        }
        return total;
    }
};


//below soln are optional

//For normal recursion has TC O(2^n) and SC O(n)

//Memoization
#include<bits/stdc++.h>
long f(int i,int buy,long *values,int n, vector<vector<long>> &dp){
    if(i==n) return 0;
    if(dp[i][buy]!=0) return dp[i][buy];

    if(buy){
        return dp[i][buy]=max(-values[i]+f(i+1,0,values,n,dp),f(i+1,1,values,n,dp));
    }else{
        return dp[i][buy]=max(values[i]+f(i,1,values,n,dp),f(i+1,0,values,n,dp));
    }
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n,vector<long> (2,0));
    return f(0,1,values,n,dp);
}
//TC is O(2n)
//SC is O(n)+O(2n)

//Tabulation
#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1,vector<long> (2,0));

    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy) dp[i][buy]=max(-values[i]+dp[i+1][0],dp[i+1][1]);
            else dp[i][buy]=max(values[i]+dp[i+1][1],dp[i+1][0]);
        }
    }
    return dp[0][1];
}

//Space optimization
#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<long> curr(2,0),next(2,0);

    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy) curr[buy]=max(-values[i]+next[0],next[1]);
            else curr[buy]=max(values[i]+next[1],next[0]);
        }
        next=curr;
    }
    return curr[1];
}

