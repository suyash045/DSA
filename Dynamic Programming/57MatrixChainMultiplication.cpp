//Partition dp
//Steps :
// 1) Start with entire array
// 2) Try all partitions(run loop)
// 3) Return the best possible 2 partitions
#include<bits/stdc++.h>
using namespace std;

//Normal recursion has TC exponential

//Memoization
//Ex. {40,20,30,10,30}
//(A(BC))D
//If we want to partition after 1st matrix A X BCD
//Two matrices will be [40X20] [20X30] hence we have to add 40X20X30
class Solution{
public:
    int f(int i,int j,int arr[],vector<vector<int>> &dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
            mini=min(steps,mini);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int> (N,-1));
        return f(1,N-1,arr,dp);
    }
};
//TC is O(n^3)
//SC is O(n) + O(n^2)

//Tabulation
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int> (N,-1));
        
        for(int i=0;i<N;i++) dp[i][i]=0;
        
        for(int i=N-1;i>=0;i--){
            for(int j=i+1;j<N;j++){
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini=min(steps,mini);
                }
                dp[i][j]=mini;
            }
        }
        
        return dp[1][N-1];
    }
};
//TC is O(n^3)
//SC is O(n^2)
