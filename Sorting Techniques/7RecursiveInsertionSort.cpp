#include<bits/stdc++.h>
using namespace std;

void insert(int arr[], int i)
{
    if(i<=0) return;
    
    insert(arr,i-1);
    
    int key=arr[i];
    int j=i-1;;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
    return;
}
//Function to sort the array using insertion sort algorithm.
void insertionSort(int arr[], int n)
{
    insert(arr,n-1);
    return;
}