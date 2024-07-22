#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution{
public:
    int f(int n,int w,int val[], int wt[],vector<vector<int>>& dp){
        if(w==0) return 0;
        if(n==0){
            if(wt[0]<=w) return val[n]*(w/wt[0]);
            return 0;
        }
        if(dp[n][w]!=0) return dp[n][w];
        
        int nottake=f(n-1,w,val,wt,dp);
        int take=0;
        if(wt[n]<=w) take=val[n]+f(n,w-wt[n],val,wt,dp);
        
        return dp[n][w]=max(nottake,take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int> (W+1,0));
        return f(N-1,W,val,wt,dp);
    }
};

//Tabulation
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int> (W+1,0));
        
        for(int i=0;i<=W;i++) dp[0][i]=val[0]*(i/wt[0]);
        
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(wt[i]<=j) take=val[i]+dp[i][j-wt[i]];
                
                dp[i][j]=max(take,nottake);
            }
        }
        
        return dp[N-1][W];
    }
};

//Space Optimization
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> prev(W+1,0),curr(W+1,0);
        
        for(int i=0;i<=W;i++) prev[i]=curr[i]=val[0]*(i/wt[0]);
        
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int nottake=prev[j];
                int take=0;
                if(wt[i]<=j) take=val[i]+curr[j-wt[i]];
                
                curr[j]=max(take,nottake);
            }
            prev=curr;
        }
        
        return curr[W];
    }
};

//Further space optimization
//We don't need all prev array we need only just one element which 
// is at index i. So we can remove prev array.
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> curr(W+1,0);
        
        for(int i=0;i<=W;i++) curr[i]=val[0]*(i/wt[0]);
        
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int nottake=curr[j];
                int take=0;
                if(wt[i]<=j) take=val[i]+curr[j-wt[i]];
                
                curr[j]=max(take,nottake);
            }
        }
        return curr[W];
    }
};