//https://leetcode.com/problems/trapping-rain-water/description/
#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int preMax[n];
        int sufMax[n];

        int maxi=0;
        for(int i=0;i<n;i++){
            preMax[i]=max(maxi,height[i]);
            maxi=preMax[i];
        }

        maxi=0;
        for(int i=n-1;i>=0;i--){
            sufMax[i]=max(maxi,height[i]);
            maxi=sufMax[i];
        }

        int sum=0;
        for(int i=1;i<n-1;i++){
            int water=min(preMax[i-1],sufMax[i+1])-height[i];
            if(water>0) sum+=water;
        }

        return sum;
    }
};

//
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int leftMax=0,rightMax=0;
        int sum=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]<leftMax){
                    sum+=leftMax-height[l];
                }
                else{
                    leftMax=height[l];
                }
                l++;
            }
            else{
                if(height[r]<rightMax){
                    sum+=rightMax-height[r];
                }
                else{
                    rightMax=height[r];
                }
                r--;
            }
        }
        return sum;
    }
};