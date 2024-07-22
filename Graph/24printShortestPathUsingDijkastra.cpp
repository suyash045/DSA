#include<bits/stdc++.h>
using namespace std;

//Use parent array to store shortest path
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int> dist(n+1,INT_MAX);
    dist[1]=0;
    
    vector<int> parent(n+1,-1);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        int node=pq.top().second;
        int distance=pq.top().first;
        pq.pop();
        
        for(auto i:adj[node]){
            if(i.second+distance<dist[i.first]){
                dist[i.first]=i.second+distance;
                pq.push({dist[i.first],i.first});
                parent[i.first]=node;
            }
        }
    }
    
    if(dist[n]==INT_MAX) return {-1};
    
    vector<int> ans;
    int i=n;
    while(parent[i]!=-1){
        ans.push_back(i);
        i=parent[i];
    }
    ans.push_back(1);
    ans.push_back(dist[n]);
    reverse(ans.begin(),ans.end());
    
    return ans;
}