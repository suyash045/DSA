#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=m;

        while(i<m+n && j<n){
            if(i==k){
                nums1[i]=nums2[j++];
                k++;
            }
            else if(nums1[i]>nums2[j]){
                int temp=k;
                while(temp!=i){
                    nums1[temp]=nums1[temp-1];
                    temp--;
                }
                nums1[i]=nums2[j];
                j++;
                k++;
            }
            i++;
        }
    }
};

//
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(k>=0 && j>=0){
            if(i>=0 && nums2[j]>=nums1[i]){
                nums1[k--]=nums2[j--];
            }
            else if(i>=0 && nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else nums1[k--]=nums2[j--];
        }
    }
};