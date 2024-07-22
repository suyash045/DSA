#include<bits/stdc++.h>
using namespace std;

//sort and select

//Better
//using heap 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }

        return pq.top();
    }
};

//Optimal
//using quick select algo(sorting only one side of array using quicksort)
int partition(vector<int>& nums,int low,int high){
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(nums[j]<nums[high]){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[high]);
    return i+1;
}
int findKthLargest(vector<int>& nums, int k) {
    int n=nums.size();
    int low=0,high=n-1,ind=n-k;

    while(low<high){
        int pi=partition(nums,low,high);
        if(pi==ind) return nums[ind];
        if(pi<ind) low=pi+1;
        else high=pi-1;
    }

    return nums[ind];
}