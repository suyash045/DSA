#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for(int i=0;i<n;i++){
        int min_ind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind]) min_ind=j;
        }
        if(min_ind!=i) swap(arr[min_ind],arr[i]);
    }
}