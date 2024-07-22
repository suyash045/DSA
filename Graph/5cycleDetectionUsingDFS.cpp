#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int node,vector<int> adj[],vector<bool> &vis,vector<int> &parent){
        vis[node]=true;
            
        for(auto i:adj[node]){
            if(!vis[i]){
                parent[i]=node;
                bool temp=dfs(i,adj,vis,parent);
                if(temp==1) return 1;
            }
            else if(vis[i] && parent[node]!=i){
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        vector<int> parent(V,-1);
        
        bool temp=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                temp=dfs(i,adj,vis,parent);
                if(temp==1) return 1;
            }
        }
        
        return 0;
    }
};