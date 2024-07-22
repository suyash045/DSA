//https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
#include<bits/stdc++.h>
using namespace std;

long long findPages(int n, int arr[], int m) {
    if(n<m) return -1;
    
    long long sum=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxi=max(maxi,arr[i]);
    }
    
    long long low=maxi,high=sum;
    while(low<=high){
        long long mid=(low+high)/2;
        
        long long pages=0;
        int cnt=1;
        for(int i=0;i<n;i++){
            pages+=arr[i];
            if(pages>mid){
                cnt++;
                pages=arr[i];
            }
        }
        
        if(cnt<=m) high=mid-1;
        
        else low=mid+1;
    }
    return low;
}