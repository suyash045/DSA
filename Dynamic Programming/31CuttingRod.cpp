#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution{
  public:
    int f(int n,int w,int price[],vector<vector<int>> &dp){
        if(w==0) return 0;
        if(n==0) return w*price[0];
        if(dp[n][w]!=0) return dp[n][w];
        
        int nottake=f(n-1,w,price,dp);
        int take=0;
        if(n+1<=w) take=price[n]+f(n,w-(n+1),price,dp);
        
        return dp[n][w]=max(take,nottake);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int> (n+1,0));
        return f(n-1,n,price,dp);
    }
};

//Tabulation
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int> (n+1,0));
        for(int i=0;i<=n;i++) dp[0][i]=price[0]*i;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(i+1<=j) take=price[i]+dp[i][j-(i+1)];
                dp[i][j]=max(take,nottake);
            }
        }
        return dp[n-1][n];
    }
};

//Space Optimization
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=0;i<=n;i++) prev[i]=curr[i]=price[0]*i;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int nottake=prev[j];
                int take=0;
                if(i+1<=j) take=price[i]+curr[j-(i+1)];
                curr[j]=max(take,nottake);
            }
            prev=curr;
        }
        return curr[n];
    }
};

//Further space optimization
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> curr(n+1,0);
        for(int i=0;i<=n;i++) curr[i]=price[0]*i;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int nottake=curr[j];
                int take=0;
                if(i+1<=j) take=price[i]+curr[j-(i+1)];
                curr[j]=max(take,nottake);
            }
        }
        return curr[n];
    }
};
