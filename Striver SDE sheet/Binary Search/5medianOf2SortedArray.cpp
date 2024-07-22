#include<bits/stdc++.h>
using namespace std;

//Apply binary search logic on one array. mid1 is no. of elements from 1st array. 
//No. of elements from 2nd array = (n1+n2+1)/2 - mid1. From the mid1 and mid2 we get l1,l2,r1,r2.
//if l1>r2 then we will decrease mid1.
//if l2>r1 then we will increase mid1.
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();

    if(n2<n1) return findMedianSortedArrays(nums2,nums1);

    int low=0,high=n1;
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=(n1+n2+1)/2-mid1;

        int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
        if(mid1-1>=0) l1=nums1[mid1-1];
        if(mid2-1>=0) l2=nums2[mid2-1];
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];

        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==1) return max(l1,l2);
            else return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }

    return 0;
}