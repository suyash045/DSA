#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int mod=2*(1e9);
    int f(int n,int m,vector<vector<int>>& obstacleGrid,vector<vector<int>> dp){
        if(m>=0 && n>=0 && obstacleGrid[n][m]==1) return dp[n][m]=0;
        if(m==0 && n==0) return dp[n][m]=1;
        if(m<0 || n<0) return 0;
       
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m]=f(n-1,m,obstacleGrid,dp)+f(n,m-1,obstacleGrid,dp)%mod;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
    }
};

//Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0,left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[n-1][m-1];
    }
};
//TC is O(n*m)
//SC is O(n*m)

//Space Optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<int> prev(m,0);

        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) curr[j]=0;
                else if(i==0 && j==0) curr[j]=1;
                else{
                    int up=0,left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=curr[j-1];
                    curr[j]=left+up;
                }
                prev=curr;
            }
        }
        return prev[m-1];
    }
};
//TC is O(n*m)
//SC is O(m)