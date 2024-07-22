#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    unordered_map<int,list<pair<int,int>>> adj; 
    for(int i=0;i<times.size();i++){
        int u=times[i][0];
        int v=times[i][1];
        int t=times[i][2];

        adj[u].push_back({v,t});
    }
    
    vector<int> time(n+1,INT_MAX);
    time[k]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,k});
    while(!pq.empty()){
        int node=pq.top().second;
        int t=pq.top().first;
        pq.pop();

        for(auto i:adj[node]){
            if(time[i.first]>t+i.second){
                time[i.first]=t+i.second;
                pq.push({time[i.first],i.first});
            }
        }
    }

    int maxi=0;
    for(int i=1;i<=n;i++){
        if(time[i]==INT_MAX) return -1;
        maxi=max(maxi,time[i]);
    }

    return maxi;
}