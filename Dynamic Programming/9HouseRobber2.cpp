#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            int pick=nums[i]+prev2;
            int unpick=prev1;

            int curr=max(pick,unpick);
            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1),solve(temp2));
    }
};