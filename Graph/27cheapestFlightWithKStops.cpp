#include<bits/stdc++.h>
using namespace std;

//Used dijkstra (priority queue sets according to stops value)
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<flights.size();i++){
        int u=flights[i][0];
        int v=flights[i][1];
        int p=flights[i][2];

        adj[u].push_back({v,p});
    }

    vector<int> dist(n,INT_MAX);
    dist[src]=0;

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,src}});

    while(!pq.empty()){
        int stops=pq.top().first;
        int price=pq.top().second.first;
        int city=pq.top().second.second;
        pq.pop();

        if(k+1==stops) continue;

        for(auto i:adj[city]){
            if(dist[i.first]>price+i.second){
                dist[i.first]=price+i.second;
                pq.push({stops+1,{dist[i.first],i.first}});
            }
        }
    }
    
    if(dist[dst]==INT_MAX) return -1;
    return dist[dst];
}