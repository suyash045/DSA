#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];

        int low=1,high=n-2;
        while(low<=high){
            int m=(low+high)/2;
            
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1]) return nums[m];

            else if((nums[m]==nums[m+1] && m%2==1) || (nums[m]==nums[m-1] && m%2==0)) high=m-1;

            else low=m+1;
        }

        return -1;
    }
};