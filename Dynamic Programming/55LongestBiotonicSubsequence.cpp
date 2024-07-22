#include<bits/stdc++.h>
using namespace std;

//Create dp from left to right and another dp from right to left.
//max of dp1[i]+dp2[i]-1 is the ans
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[j]<nums[i]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
            }
        }
        
        vector<int> dp2(n,1);
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i+1;j--){
                if(nums[j]<nums[i] && dp2[i]<1+dp2[j]){
                    dp2[i]=1+dp2[j];
                }
            }
            if(dp1[i]>=2 && dp2[i]>=2) maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        
        return maxi; 
    }
};