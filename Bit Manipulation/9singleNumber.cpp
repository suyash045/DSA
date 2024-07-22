//Array contains duplicate numbers only one number is single
#include<bits/stdc++.h>
using namespace std;

//XOR of two same numbers is 0
//2^2=0
int singleNumber(vector<int>& nums) {
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans=ans^nums[i];
    }
    return ans;
}