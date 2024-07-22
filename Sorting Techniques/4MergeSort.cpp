#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int an=m-l+1;
    int bn=r-m;
    int a[an],b[bn];
    
    for(int i=0;i<an;i++) a[i]=arr[l+i];
    for(int i=0;i<bn;i++) b[i]=arr[m+1+i];
    
    int i=0,j=0,k=l;
    while(i<an && j<bn){
        if(a[i]>b[j]) arr[k++]=b[j++];
        else arr[k++]=a[i++];
    }
    
    while(i<an){
        arr[k++]=a[i++];
    }
    
    while(j<bn){
        arr[k++]=b[j++];
    }
    return ;
}
void mergeSort(int arr[], int l, int r)
{
    if(l>=r) return;
    
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
    return;
}