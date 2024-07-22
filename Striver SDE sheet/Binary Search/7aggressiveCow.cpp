//https://www.geeksforgeeks.org/problems/aggressive-cows/0
#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end());
    int low=0;
    int high=stalls[n-1]-stalls[0];
    
    while(low<=high){
        int mid=(low+high)/2;
        
        int cnt=1,dist=0,lastCow=stalls[0];
        for(int i=1;i<n;i++){
            dist=stalls[i]-lastCow;
            if(dist>=mid){
                cnt++;
                lastCow=stalls[i];
            }
        }
        
        if(cnt>=k) low=mid+1;
        
        else high=mid-1;
    }
    
    return high;
}