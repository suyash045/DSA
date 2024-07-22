#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
  public:
    int solve(vector<vector<int>>& points, int n,int a,vector<vector<int>> &dp){
    
        int maxi=0;
        for(int task=0;task<=2;task++){
            int x=0;
            if(n-1>=0 && a!=task){ 
                if(dp[n][task]!=-1) x=dp[n][task];
                else{
                    x=points[n][task]+solve(points,n-1,task,dp);
                    dp[n][task]=x;
                }
            }
            else if(n==0 && a!=task) x=points[n][task];
            
            maxi=max(maxi,x);
        }
        
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n,vector<int> (3,-1));
        return solve(points,n-1,-1,dp);
    }
};
//TC is O(n*4*3) (doubtful)
//SC is O(n)+O(n*3)

//Tabulation
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n,vector<int> (3,-1));
        dp[0][0]=points[0][0];
        dp[0][1]=points[0][1];
        dp[0][2]=points[0][2];
        for(int i=1;i<n;i++){
            for(int task=0;task<=2;task++){
                int maxi=0;
                for(int j=0;j<=2;j++){
                    if(j!=task){
                        maxi=max(maxi,dp[i-1][j]);
                    }
                }
                dp[i][task]=points[i][task]+maxi;    
            }
        }
        return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    }
};

//Space Optimization
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<int> dp(4,-1);
        dp[0]=points[0][0];
        dp[1]=points[0][1];
        dp[2]=points[0][2];
        
        for(int i=1;i<n;i++){
            int a=max(dp[1],dp[2]);
            int b=max(dp[0],dp[2]);
            int c=max(dp[0],dp[1]);
            dp[0]=points[i][0]+a;
            dp[1]=points[i][1]+b;
            dp[2]=points[i][2]+c;
        }
        return max(dp[0],max(dp[1],dp[2]));
    }
};
//TC is O(n*4*3)
//SC is O(4)