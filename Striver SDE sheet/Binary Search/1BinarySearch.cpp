#include<iostream>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>current){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    return;
}
void binarySearch(int arr[],int n,int key){
    int beg=0,end=n-1;
    while(beg<=end){
        int mid=(beg+end)/2;
        if(arr[mid]==key){
            cout<<"Key found at index "<<mid;
            return;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    int key;
    cout<<"Key : ";
    cin>>key;
    binarySearch(arr,n,key);
return 0;
}
//TC is O(logn) base is 2