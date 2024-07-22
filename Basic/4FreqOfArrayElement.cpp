#include<bits/stdc++.h>
using namespace std;

//We have to do counting in place of original array.
//We storing counting -ve

//Ex. {2,3,2,3,5}
// i=0
// {3,-1,2,3,5}
// {2,-1,-1,3,5}
// i=2
// {0,-2,-1,3,5}
// i=3
// {0,-2,-2,0,5}
// i=4
// {0,-2,-2,0,5}
// i=5
// {0,-2,-2,0,-1}
//final ans : {0,2,2,0,1}

class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    {   
        int i=0;
        while(i<N){
            if(arr[i]<=0 || arr[i]>N || arr[i]>P){
                i++;
                continue;    
            }
            
            if(arr[i]>0){
                int index=arr[i]-1;
                
                if(arr[index]>0){
                    arr[i]=arr[index];
                    arr[index]=-1;
                }else{
                    arr[index]--;
                    arr[i]=0;
                    i++;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(arr[i]<0) arr[i]=-arr[i];
            else arr[i]=0;
        }
        return;
    }
};