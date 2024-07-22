#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int low, int high)
{
    if(low<high){
        int pIndex=partition(arr,low,high);
        
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }
}
int partition (int arr[], int low, int high)
{
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<arr[high]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}