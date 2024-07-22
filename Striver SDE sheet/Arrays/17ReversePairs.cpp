#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((long long)nums[i]>2*(long long)nums[j]) cnt++;
            }
        }

        return cnt;
    }
};

//optimal
class Solution {
public:
    long long merge(vector<int>& nums,int l,int mid, int r){
        long long cnt=0;
        int an=mid-l+1;
        int bn=r-mid;

        long long a[an];
        long long b[bn];
        for(int i=0;i<an;i++) a[i]=nums[l+i];
        for(int j=0;j<bn;j++) b[j]=nums[mid+1+j];

        //Additional code starts here
        int left=0,right=0;
        while(left<an && right<bn){
            if (a[left] > 2*b[right]) {
                cnt+=+an-left;
                right++;
            }
            else left++;
        }
        //Additional code ends here

        int i=0,j=0,k=l;
        while(i<an && j<bn){
            if(a[i]<b[j]) nums[k++]=a[i++];
            else nums[k++]=b[j++];
        }

        while(i<an){
            nums[k++]=a[i++];
        }
        while(j<bn){
            nums[k++]=b[j++];
        }
        return cnt;
    }
    long long mergeSort(vector<int>& nums,int l, int r){
        long long cnt=0;
        if(l>=r) return cnt;
        
        int mid=(l+r)/2;
        cnt+=mergeSort(nums,l,mid);
        cnt+=mergeSort(nums,mid+1,r);
        cnt+=merge(nums,l,mid,r);
        return cnt;
    } 
    int reversePairs(vector<int>& nums){
        int n=nums.size(); 
        return (int)mergeSort(nums,0,n-1);
    }
};