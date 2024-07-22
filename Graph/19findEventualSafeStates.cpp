//by using topo sort
#include<bits/stdc++.h>
using namespace std;

//apply topo sort to reversed graph(change the direction of arrows)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,list<int>> adj;
        int n=graph.size();
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        set<int> s;
        while(!q.empty()){
            int front=q.front();
            q.pop();

            s.insert(front);
            for(auto i:adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(s.find(i)!=s.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};