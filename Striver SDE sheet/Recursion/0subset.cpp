#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    for(int i=0;i<=(pow(2,n)-1);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if((i & (1<<j))!=0) sum+=arr[j];
        }
        ans.push_back(sum);
    }
    
    sort(ans.begin(),ans.end());
    return ans; 
}