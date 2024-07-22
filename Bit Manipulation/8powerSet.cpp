#include<bits/stdc++.h>
using namespace std;

//Ex. {10,20,30}
//0 000 {}
//1 001 {30}
//2 010 {20}
//3 011 {20,30}
//4 100 {10}
//5 101 {10,30}
//6 110 {10,20}
//7 111 {10,20,30}
vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    int N=pow(2,n);
    vector<vector<int>> ans;
    for(int i=0;i<N;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            if((i & (1<<j))!=0) temp.push_back(nums[j]); 
        }
        ans.push_back(temp);
    }
    return ans;
}