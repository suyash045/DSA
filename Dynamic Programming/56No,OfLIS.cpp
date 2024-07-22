#include<bits/stdc++.h>
using namespace std;

//Create count array
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),count(n,1);
        int maxi=1; 
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1){
                    count[i]=count[j];
                    dp[i]=1+dp[j];
                }
                else if(nums[j]<nums[i] && dp[i]==dp[j]+1) count[i]+=count[j];
            }
            if(maxi<dp[i]){
                maxi=dp[i];
            }
        }
        int totalCount=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) totalCount+=count[i];
        }

        return totalCount;
    }
};