//Subarray are continous

#include<bits/stdc++.h>
using namespace std;

//Brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                }
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};
//TC is O(n^3)
//SC is O(1)

//Better approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};
//TC is O(n^2)

//Optimal approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum<=0){
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
//O(n)

//Printing of subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        int start=-1;
        int ansStart=-1;
        int ansEnd=n-1;
        for(int i=0;i<n;i++){
            if(sum<=0){
                start=i;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
            if(sum>maxi){
                maxi=sum;
                ansStart=start;
                ansEnd=i;
            }
        }
        return maxi;
    }
};