#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=0;i<n;i++){
        bool isSwap=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=1;
            }
        }
        if(isSwap==0) break;
    }
}