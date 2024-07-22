#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution{
	public:
	int f(int n,vector<int>& arr,int sum,vector<vector<int>> dp){
	    if(n==0){ 
	        if(sum==0 && arr[0]==0) return 2;
	        if(sum==0 || sum==arr[0]) return 1;
	        return 0;
	    }
	    if(dp[n][sum]!=-1) return dp[n][sum];
	    
	    int nottake=f(n-1,arr,sum,dp);
	    int take=0;
	    if(arr[n]<=sum) take=f(n-1,arr,sum-arr[n],dp); 
	    return dp[n][sum]=nottake+take;
	}
	int perfectSum(vector<int>& arr, int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return f(n-1,arr,sum,dp);
	}	
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        
        if((sum-d)%2==1 || (sum-d)<0) return 0;
        
        int s2=(sum-d)/2;
        return perfectSum(arr,n,s2);
    } 
};

//Tabulation
class Solution {
  public:
    int mod=1e9+7;
	int perfectSum(vector<int>& arr, int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int> (sum+1,0));
        
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        
        if(arr[0]!=0 && arr[0]<=sum) dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(arr[i]<=j) take=dp[i-1][j-arr[i]];
                dp[i][j]=(take+nottake)%mod;
            }
        }
        return dp[n-1][sum];
	}
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        
        if((sum-d)%2==1 || (sum-d)<0) return 0;
        
        int s2=(sum-d)/2;
        return perfectSum(arr,n,s2);
    }
};

//Space Optimization
class Solution {
  public:
    int mod=1e9+7;
	int perfectSum(vector<int>& arr, int n, int sum)
	{
	    vector<int> curr(sum+1,0),prev(sum+1,0);
        
        if(arr[0]==0) prev[0]=curr[0]=2;
        else prev[0]=curr[0]=1;
        
        if(arr[0]!=0 && arr[0]<=sum) prev[arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int nottake=prev[j];
                int take=0;
                if(arr[i]<=j) take=prev[j-arr[i]];
                curr[j]=(take+nottake)%mod;
            }
            prev=curr;
        }
        return prev[sum];
	}
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        
        if((sum-d)%2==1 || (sum-d)<0) return 0;
        
        int s2=(sum-d)/2;
        return perfectSum(arr,n,s2);
    }
};