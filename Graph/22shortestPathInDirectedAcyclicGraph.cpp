#include<bits/stdc++.h>
using namespace std;

//same prev que logic
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<M;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
    }
    
    vector<int> dist(N,INT_MAX);
    dist[0]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int node=q.front().first;
        int distance=q.front().second;
        q.pop();
        
        for(auto i:adj[node]){
            if(i.second+distance<dist[i.first]){
                dist[i.first]=i.second+distance;
                q.push({i.first,dist[i.first]});
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(dist[i]==INT_MAX) dist[i]=-1;
    }
    
    return dist;
}