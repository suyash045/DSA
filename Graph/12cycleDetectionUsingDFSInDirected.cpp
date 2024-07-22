#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int node,vector<int> adj[],vector<bool> &vis,vector<bool> dfsVis){
        vis[node]=true;
        dfsVis[node]=true;
            
        for(auto i:adj[node]){
            if(!vis[i]){
                bool temp=dfs(i,adj,vis,dfsVis);
                if(temp==1) return 1;
            }
            else if(vis[i] && dfsVis[i]){
                return 1;
            }
        }
        return 0;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        vector<bool> dfsVis(V);
        
        bool temp=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                temp=dfs(i,adj,vis,dfsVis);
                if(temp==1) return 1;
            }
        }
        
        return 0;
    }
};