//https://www.naukri.com/code360/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
using namespace std;

//Memoization
int f(int n,vector<int>& arr,int sum,vector<vector<int>> &dp){
    if(sum==0) return 1;
	if(n==0) return (arr[0]==sum);
	if(dp[n][sum]!=-1) return dp[n][sum]; 
    int nottake=f(n-1,arr,sum,dp);
	int take=0;
    if(arr[n]<=sum) take=f(n-1,arr,sum-arr[n],dp); 
	return dp[n][sum]=nottake+take;
}
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>> dp(n,vector<int> (k+1,-1));
	return f(n-1,arr,k,dp);
}

//Tabulation
int findWays(vector<int>& arr, int k)
{
	int mod=1e9+7;
	int n=arr.size();
	vector<vector<int>> dp(n,vector<int> (k+1,0));
	dp[0][0]=1;
	if(arr[0]<=k) dp[0][arr[0]]=1;

	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			int nottake=dp[i-1][j];
			int take=0;
			if(arr[i]<=j) take=dp[i-1][j-arr[i]];
			dp[i][j]=(take+nottake)%mod;
		}
	}

	return dp[n-1][k]%mod;
}

//Space Optimization
int findWays(vector<int>& arr, int k)
{
	int mod=1e9+7;
	int n=arr.size();
	vector<int> curr(k+1,0),prev(k+1,0);
	prev[0]=curr[0]=1;
	if(arr[0]<=k) prev[arr[0]]=1;

	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			int nottake=prev[j];
			int take=0;
			if(arr[i]<=j) take=prev[j-arr[i]];
			curr[j]=(take+nottake)%mod;
		}
		prev=curr;
	}

	return prev[k]%mod;
}
