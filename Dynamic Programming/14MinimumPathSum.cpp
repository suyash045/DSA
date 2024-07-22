#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int f(int n,int m,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(n==0 && m==0) return grid[n][m];
        if(n<0 || m<0) return 1e7;
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m]=min(grid[n][m]+f(n-1,m,grid,dp),grid[n][m]+f(n,m-1,grid,dp));
    } 
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(n-1,m-1,grid,dp);
    }
};

//Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=1e4,left=1e4;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=grid[i][j]+min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

//Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> prev(m,0);
    
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) curr[j]=grid[i][j];
                else{
                    int up=1e4,left=1e4;
                    if(i>0) up=prev[j];
                    if(j>0) left=curr[j-1];
                    curr[j]=grid[i][j]+min(up,left);
                }
            }
            prev=curr;
        }
        return prev[m-1];
    }
};