#include<bits/stdc++.h>
using namespace std;

//Use dfsVisited array and set(to store ans)
class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<bool> &vis,vector<bool> &dfsVis,set<int> &s){
        vis[node]=dfsVis[node]=1;
        for(int i=0;i<graph[node].size();i++){
            if(!vis[graph[node][i]]){
                bool temp=dfs(graph[node][i],graph,vis,dfsVis,s);
                if(temp==false) return false;
            }
            else if(dfsVis[graph[node][i]]){
                return false;
            }
            else if(s.find(graph[node][i])==s.end()){
                return false;
            }
        }
        s.insert(node);
        dfsVis[node]=false;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                indegree[graph[i][j]]++;
            }
        }

        set<int> s;
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                vector<bool> dfsVis(n,0);
                bool temp=dfs(i,graph,vis,dfsVis,s);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<bool> dfsVis(n,0);
                bool temp=dfs(i,graph,vis,dfsVis,s);
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