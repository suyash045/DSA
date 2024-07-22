#include<bits/stdc++.h>
using namespace std;

//store when you are doing work do work near deadline
struct Job 
{ 
    int id;	 
    int dead; 
    int profit; 
};
class Solution 
{
    public:
    static bool comparison(Job a,Job b){
        return (a.profit>b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n, comparison);
        
        int maxDead=0;
        for(int i=0;i<n;i++) maxDead=max(maxDead,arr[i].dead);
        
        vector<int> work(maxDead+1,-1);
        
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            int j=arr[i].dead;
            
            while(j>0 && work[j]!=-1) j--;
            if(j>0){
                work[j]=0;
                sum+=arr[i].profit;
                cnt++;
            }
        }
        
        return {cnt,sum};
    } 
};