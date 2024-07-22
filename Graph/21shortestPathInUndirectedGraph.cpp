#include<bits/stdc++.h>
using namespace std;

//Create distance array and do bfs
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<M;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(N,INT_MAX);
    dist[src]=0;
    queue<pair<int,int>> q;
    q.push({src,0});
    while(!q.empty()){
        int node=q.front().first;
        int distance=q.front().second;
        q.pop();
        
        for(auto i:adj[node]){
            if(1+distance<dist[i]){
                dist[i]=1+distance;
                q.push({i,dist[i]});
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(dist[i]==INT_MAX) dist[i]=-1;
    }
    
    return dist;
}