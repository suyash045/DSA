//https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
	for(int i=0;i<n;i++) sum+=arr[i];

	int k=sum/2;

    //Subset sum code
	vector<vector<bool>> dp(n,vector<bool> (k,0));
	for(int i=0;i<n;i++) dp[i][0]=true;
	if(arr[0]<=k) dp[0][arr[0]]=true;

	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			bool nottake=dp[i-1][j];
			bool take=0;
			if(arr[i]<=j) take=dp[i-1][j-arr[i]];
			dp[i][j]=take|nottake;
		}
	}

    //new code
	int s1=0;
	for(int i=0;i<=k;i++){
		if(dp[n-1][i]!=0){
			s1=i;
		}
	}
	int s2=sum-s1;
	return s2-s1;
}

