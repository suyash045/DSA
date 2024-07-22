//https://leetcode.com/problems/global-and-local-inversions/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        int bound=0;
        for(int i=2;i<n;i++){
            bound=max(bound,nums[i-2]);
            if(nums[i]<bound) return false;
        }
        return true;
    }
};