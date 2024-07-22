#include<bits/stdc++.h>
using namespace std;

//1st two fn are only for counting
int upperBound(vector<int> matrix,int x,int C){
    int ans=C;
    int low=0,high=C-1;
    while(low<=high){
        int mid=(low+high)/2;
        
        if(matrix[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int countSmallEqual(vector<vector<int>> &matrix,int x,int R,int C){
    int cnt=0;
    for(int i=0;i<R;i++){
        cnt+=upperBound(matrix[i],x,C);
    }
    return cnt;
}
int median(vector<vector<int>> &matrix, int R, int C){
    int req=(R*C)/2;
    int low=INT_MAX,high=INT_MIN;
    for(int i=0;i<R;i++){
        high=max(high,matrix[i][C-1]);
        low=min(low,matrix[i][0]);
    }
    while(low<=high){
        int mid=(low+high)/2;
        
        int smallEqual=countSmallEqual(matrix,mid,R,C);
        if(smallEqual<=req) low=mid+1;
        else high=mid-1;
    }
    
    return low;
}
//TC is O(log(10^9) * nlogm)
