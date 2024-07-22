#include<bits/stdc++.h>
using namespace std;

//Do merge sort 
//And while merging two sorted array count inversions by using loop
long long merge(long long *arr,int l,int mid, int r){
    long long cnt=0;
    int an=mid-l+1;
    int bn=r-mid;

    long long a[an];
    long long b[bn];
    for(int i=0;i<an;i++) a[i]=arr[l+i];
    for(int j=0;j<bn;j++) b[j]=arr[mid+1+j];

    //code to count inversions of two sorted array
    int left=0,right=0;
    while(left<an && right<bn){
      if (a[left] > b[right]) {
        cnt=cnt+an-left;
        right++;
      }
      else left++;
    }
    //code ends here

    int i=0,j=0,k=l;
    while(i<an && j<bn){
        if(a[i]<b[j]) arr[k++]=a[i++];
        else arr[k++]=b[j++];
    }

    while(i<an){
        arr[k++]=a[i++];
    }
    while(j<bn){
        arr[k++]=b[j++];
    }
    return cnt;
}
long long mergeSort(long long *arr,int l, int r){
    long long cnt=0;
    if(l>=r) return cnt;
    
    int mid=(l+r)/2;
    cnt+=mergeSort(arr,l,mid);
    cnt+=mergeSort(arr,mid+1,r);
    cnt+=merge(arr,l,mid,r);
    return cnt;
} 
long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}