//array contains elements 3 times only 1 element occurs once 
#include<bits/stdc++.h>
using namespace std;

//We can do hashing

//Better approach
//Ex. {5,5,5,6,4,4,4,}
//5 101
//5 101
//5 101
//6 110
//4 010 
//4 010
//4 010
int singleNumber(vector<int>& nums) {
    int ans=0;
    for(int i=0;i<32;i++){
        int cnt=0;
        for(int j=0;j<nums.size();j++){
            if((nums[j] & (1<<i))!=0) cnt++; 
        }
        if(cnt%3==1) ans=ans | (1<<i);
    }
    return ans;
}

//By sorting array
int singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());

    for(int i=1;i<nums.size();i=i+3){
        if(nums[i]!=nums[i-1]) return nums[i-1];
    }
    return nums[nums.size()-1];
}

//Use 2 buckets : ones, twos
//ones store bits coming 1 time or 4, 7, 10,...
//twos store bits coming 2 time or 5, 8, 11,...
//if bit is 3 time or 6, 9, 12,... then that bit is 0 in both ones and twos
int singleNumber(vector<int>& nums) {
    int ones=0,twos=0;
    for(int i=0;i<nums.size();i++){
        ones= (ones^nums[i]) & (~twos);
        twos= (twos^nums[i]) & (~ones);
    }
    return ones;
}
//TC is O(n)
//SC is O(1)