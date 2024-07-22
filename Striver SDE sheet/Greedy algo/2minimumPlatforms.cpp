#include<bits/stdc++.h>
using namespace std;

//sort both arrival and departure array
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    
    int s=0,d=0;
    int cnt=0,maxi=0;
    while(s!=n){
        if(arr[s]>dep[d]){
            d++;
            cnt--;
        }
        else{
            cnt++;
            s++;
        }
        maxi=max(maxi,cnt);
    }
    
    return maxi;
}