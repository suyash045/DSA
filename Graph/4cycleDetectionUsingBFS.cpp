#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool bfs(int node,vector<int> adj[],vector<bool> &vis,vector<int> &parent){
        queue<int> q;
        q.push(node);
        vis[node]=true;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto i:adj[front]){
                if(!vis[i]){
                    q.push(i);
                    parent[i]=front;
                    vis[i]=true;
                }
                else if(vis[i] && parent[front]!=i){
                    return 1;
                }
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
                temp=bfs(i,adj,vis,parent);
                if(temp==1) return 1;
            }
        }
        
        return 0;
    }
};