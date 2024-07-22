#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            //if(nums[i]<=target){
                for(int j=i-1;j>=0;j--){
                    if(nums[i]+nums[j]==target){
                        return {i,j};
                    }
                }
            //}
        }

        return {0,0};
    }
};

//Optimal
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> present;
        for(int i=n-1;i>=0;i--){            
            if(present[target-nums[i]]!=0){
                return {present[target-nums[i]],i};
            } 
            present[nums[i]]=i;
        }

        return {0,0};
    }
};