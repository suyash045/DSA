#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp,int n){
        if(i==n-1) return dp[i][j]=triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int down=f(i+1,j,triangle,dp,n);
        int right=f(i+1,j+1,triangle,dp,n);

        return dp[i][j]=min(down,right)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(0,0,triangle,dp,n);
    }
};

//Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i==n-1) dp[i][j]=triangle[i][j];
                else{
                    int down=dp[i+1][j];
                    int dia=dp[i+1][j+1];
                    dp[i][j]=min(down,dia)+triangle[i][j];
                } 
            }
        }
        return dp[0][0];
    }
};

//Space Optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> front(n,-1),curr(n,-1);
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i==n-1) curr[j]=triangle[i][j];
                else{
                    int down=front[j];
                    int dia=front[j+1];
                    curr[j]=min(down,dia)+triangle[i][j];
                } 
            }
            front=curr;
        }
        return front[0];
    }
};