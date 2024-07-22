#include<bits/stdc++.h>
using namespace std;
//Memoization
class Solution {
public:
    int f(int i,int n,vector<int>& arr, int k,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=0) return dp[i];

        int len=0,maxi=0,ans=0;
        for(int j=i;j<min(n,i+k);j++){
            maxi=max(maxi,arr[j]);
            len++;
            int value=len*maxi+f(j+1,n,arr,k,dp);
            ans=max(ans,value);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,0);
        return f(0,n,arr,k,dp);
    }
};
//TC is O(n*k)
//SC is O(n)+O(n)

//Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int len=0,maxi=0,ans=0;
            for(int j=i;j<min(n,i+k);j++){
                maxi=max(maxi,arr[j]);
                len++;
                int value=len*maxi+dp[j+1];
                ans=max(ans,value);
            }
            dp[i]=ans;
        }

        return dp[0];
    }
};

//Space Optimization
