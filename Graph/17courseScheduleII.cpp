#include<bits/stdc++.h>
using namespace std;

//Use kahn's algo
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();

            ans.push_back(front);

            for(auto i:adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()==n) return ans;
        else return {};
    }
};