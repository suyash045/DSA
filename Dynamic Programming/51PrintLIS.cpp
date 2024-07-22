#include<bits/stdc++.h>
using namespace std;

//We created hash array similar to parent array
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n,1),hash(n,0);
        int maxi=dp[0];
        int u=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<=i-1;j++){
                if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                u=i;
            }
        }
        vector<int> ans;
        while(hash[u]!=u){
            ans.push_back(arr[u]);
            u=hash[u];
        }
        ans.push_back(arr[u]);
        reverse(ans.begin(),ans.end());

        return ans;
    }
};