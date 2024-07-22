#include<bits/stdc++.h>
using namespace std;

//Use Kahn's algo
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,list<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int> indegree(n,0);
        for(auto i:adj){
            for(auto j:i.second) indegree[j]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        int cnt=0;
        while(!q.empty()){
            cnt++;
            int node=q.front();
            q.pop();

            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(cnt==n) return 1;
        return 0;
    }
};