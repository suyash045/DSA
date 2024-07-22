//Array contains all duplicate number only 2 numbers are unique
#include<bits/stdc++.h>
using namespace std;

//Ex. {1,2,1,3,2,5}
//X=3^5 =110
//by using rightmost set bit of X we will divide elements into 2 buckets
//Bucket 1: elements having set bit and 3
//Bucket 2: elements having set bit and 5
vector<int> singleNumber(vector<int>& nums) {
    int n=nums.size();
    long long X=0;
    for(int i=0;i<n;i++){
        X=X^nums[i];
    }

    //for rightmost bit
    X=(X & (X-1)) ^ X;

    int a=0,b=0;
    for(int i=0;i<n;i++){
        if((nums[i] & X)!=0) a=a^nums[i];
        else b=b^nums[i];
    }

    return {a,b};
}