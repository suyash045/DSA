// https://www.geeksforgeeks.org/problems/path-in-matrix3805/1
#include<bits/stdc++.h>
using namespace std;
//Normal Recursion solution has TC O(3^n) and SC O(n)

//Memoization
class Solution{
public:
    int f(int n,int m,int i, vector<vector<int>> &Matrix,vector<vector<int>> &dp){
        if(n==0) return dp[n][i]=Matrix[0][i];
        if(dp[n][i]!=-1) return dp[n][i];
        
        int left=0,right=0;
        int up=f(n-1,m,i,Matrix,dp);
        if(i-1>=0) left=f(n-1,m,i-1,Matrix,dp);
        if(i+1<=m) right=f(n-1,m,i+1,Matrix,dp);
        
        return dp[n][i]= Matrix[n][i]+max(up,max(left,right));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int> (N,-1));
    
        int maxi=0;
        for(int i=0;i<N;i++){
            maxi=max(maxi,f(N-1,N-1,i,Matrix,dp));
        }
        return maxi;
    }
};
//TC is O(n*m)
//SC is O(n)+O(n*m)

//Tabulation
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int> (N,-1));
       
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==0) dp[0][j]=Matrix[i][j];
                else{
                    int left=0,right=0;
                    if(j>0) left=dp[i-1][j-1];
                    if(j<N-1) right=dp[i-1][j+1];
                    int up=dp[i-1][j];
                    
                    dp[i][j]=Matrix[i][j]+max(up,max(left,right));
                }
            }
        }
        
        int maxi=0;
        for(int i=0;i<N;i++){
            maxi=max(maxi,dp[N-1][i]);
        }
       
        return maxi;
    }
};
//TC is O(n*m)+O(m)
//SC is O(n*m)

//Space Optimization
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<int> curr(N,0),prev(N,0);
       
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==0) curr[j]=Matrix[i][j];
                else{
                    int left=0,right=0;
                    if(j>0) left=prev[j-1];
                    if(j<N-1) right=prev[j+1];
                    int up=prev[j];
                    
                    curr[j]=Matrix[i][j]+max(up,max(left,right));
                }
            }
            prev=curr;
        }
        
        int maxi=0;
        for(int i=0;i<N;i++){
            maxi=max(maxi,curr[i]);
        }
       
        return maxi;
    }
};
//TC is O(n*m)+O(m)
//SC is O(m)
