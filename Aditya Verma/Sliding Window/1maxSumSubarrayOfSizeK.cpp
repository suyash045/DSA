//https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
#include<bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, vector<int> &Arr , int N){
    long sum=0;
    for(int i=0;i<K;i++) sum+=Arr[i];
    
    long maxi=sum;
    
    for(int i=K;i<N;i++){
        sum=sum+Arr[i]-Arr[i-K];
        
        maxi=max(sum,maxi);
    }
    return maxi;
}