#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1) return intervals;

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            else{
                ans.back()[1]=max({ans.back()[1],intervals[i][1]});
            }
        }

        return ans;
    }
};