#include<bits/stdc++.h>
using namespace std;

//sort the array
//use similar logic as LIS
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        int maxi=1,u=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<=i-1;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
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
            ans.push_back(nums[u]);
            u=hash[u];
        }
        ans.push_back(nums[u]);
        return ans;
    }
};