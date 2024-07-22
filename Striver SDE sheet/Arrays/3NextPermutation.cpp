#include<bits/stdc++.h>
using namespace std;

//Brute force solution :
//Generate all permutation in ascending order like in dictionary
//Then search where is the present input
//Then ans will be its next permutation
//TC is O(n!*n)
//Ex. {3,1,2}
//{1,2,3}
//{1,3,2}
//{2,1,3}
//{2,3,1}
//{3,1,2} i/p
//{3,2,1} ans

//We can use STL
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};

//Implementation of STL
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1,nums.end());
        return;
    }
};
