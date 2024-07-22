#include<bits/stdc++.h>
using namespace std;

void f(int arr[],int n){
    if(n<=0) return;
    bool isSwap=0;
    for(int j=0;j<=n-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            isSwap=1;
        }
    }
    if(isSwap==0) return;
    
    f(arr,n-1);
    return;
}
void bubbleSort(int arr[], int n) {
    f(arr,n-1);
    return;
}