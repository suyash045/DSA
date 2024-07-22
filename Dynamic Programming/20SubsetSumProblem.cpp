//TC is O(2^n)
//SC is O(n)
#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution{   
public:
    bool f(int n,vector<int> &arr,int sum,vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(n==0) return (arr[n]==sum); 
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        bool nottake=f(n-1,arr,sum,dp);
        bool take=0;
        if(arr[n]<=sum) take=f(n-1,arr,sum-arr[n],dp);
        
        return dp[n][sum]=(take || nottake);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        return f(n-1,arr,sum,dp);
    }
};
//TC is O(n*sum)
//SC is O(n*sum)+O(n)

//Tabulation
//DP array:
//Ex. {3,34,4,12,5,2} targetSum=9
//      0 1 2 3 4 5 6 7 8 9 
//
//3  0  1 0 0 1 0 0 0 0 0 0 
//34 1  1 0 0 1 0 0 0 0 0 0 
//4  2  1 0 0 1 1 0 0 1 0 0 
//12 3  1 0 0 1 1 0 0 1 0 0 
//5  4  1 0 0 1 1 1 0 1 1 1 
//2  5  1 0 1 1 1 1 1 1 1 1 
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool> (sum+1,0));
        
        for(int i=0;i<n;i++) dp[i][0]=true;;
        dp[0][arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(arr[i]<=j) take=dp[i-1][j-arr[i]];
                dp[i][j]=take | nottake;
            }
        }
        return dp[n-1][sum];
    }
};
//TC O(n*target)
//SC O(n*target)

//Space Optimization
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<bool> curr(sum+1,0),prev(sum+1,0);
        
        curr[0]=prev[0]=true;;
        prev[arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nottake=prev[j];
                bool take=false;
                if(arr[i]<=j) take=prev[j-arr[i]];
                curr[j]=take | nottake;
            }
            prev=curr;
        }
        return curr[sum];
    }
};
//TC is O(n*target)
//SC is O(target)

//Initially Dp array made is (n=5,sum=7)
//   0 1 2 3 4 6 7
// {{1,0,0,1,0,0,0},
//  {1,0,0,0,0,0,0}, 
//  {1,0,0,0,0,0,0}, 
//  {1,0,0,0,0,0,0}, 
//  {1,0,0,0,0,0,0}} 
//
// Here the from the last element we can say we get the target sum or not
// And from the last row we can say if we can get the sum equal to that index
// And similarly previous row says if we can get target sum or not 