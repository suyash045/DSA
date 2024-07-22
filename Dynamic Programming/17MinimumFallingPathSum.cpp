#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int f(int n,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(n==0) return dp[n][j]=matrix[n][j];
        if(dp[n][j]!=-1) return dp[n][j];
        int left=1e7,right=1e7;

        int up=f(n-1,j,matrix,dp);
        if(j>0) left=f(n-1,j-1,matrix,dp);
        if(j<matrix.size()-1) right=f(n-1,j+1,matrix,dp);

        return dp[n][j]=matrix[n][j]+min(up,min(left,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));

        int mini=1e7;
        for(int i=0;i<n;i++) mini=min(mini,f(n-1,i,matrix,dp));

        return mini;
    }
};

//Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0) dp[i][j]=matrix[i][j];
                else{
                    int up=dp[i-1][j],left=1e7,right=1e7;
                    if(j>0) left=dp[i-1][j-1];
                    if(j<n-1) right=dp[i-1][j+1];

                    dp[i][j]=matrix[i][j] +min(up,min(left,right));
                }
            }
        }

        int mini=1e7;
        for(int i=0;i<n;i++) mini=min(mini,dp[n-1][i]);

        return mini;
    }
};

//Space Optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> curr(n,-1),prev(n,-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0) curr[j]=matrix[i][j];
                else{
                    int up=prev[j],left=1e7,right=1e7;
                    if(j>0) left=prev[j-1];
                    if(j<n-1) right=prev[j+1];

                    curr[j]=matrix[i][j] +min(up,min(left,right));
                }
            }
            prev=curr;
        }

        int mini=1e7;
        for(int i=0;i<n;i++) mini=min(mini,curr[i]);

        return mini;
    }
};