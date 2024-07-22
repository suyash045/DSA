#include<bits/stdc++.h>
using namespace std;

//
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        
        int sum=0;
        for(int i=0;i<n;i++) sum+=A[i];
        
        int maxi=0;
        for(int i=0;i<n;i++){
            int temp=sum;
            for(int j=n-1;j>=i;j--){
                if(sum==0) maxi=max(maxi,j-i+1);
                sum=sum-A[j];
            }
            sum=temp;
            sum=sum-A[i];
        }
        
        return maxi;
    }
};

//
class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
        int sum=0;
        int maxi=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0) maxi=max(maxi,i+1);
            else if (m[sum]!=0) maxi=max(maxi,i+1-m[sum]);
            
            if(m[sum]!=0) m[sum]=min(i+1,m[sum]);
            else m[sum]=i+1;
        }
    
        return maxi;
    }
};
