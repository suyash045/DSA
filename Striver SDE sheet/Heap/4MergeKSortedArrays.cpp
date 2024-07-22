#include<bits/stdc++.h>
using namespace std;

class Compare{
public:
    bool operator()(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
        return a.first > b.first;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,Compare> pq;
    for(int i=0;i<k;i++){
      pq.push({kArrays[i][0], {i, 0}});
    } 
    while(pq.size()>0){
        int data=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;

        ans.push_back(data);
        pq.pop();

        if(j+1<kArrays[i].size()){
            pq.push({kArrays[i][j + 1], {i, j + 1}});
        }
    }
    return ans;
}
