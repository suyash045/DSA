#include<bits/stdc++.h>
using namespace std;

//Djkastra doesn't work for negative edges
//Because negative edge infinite loop can be formed

//prev code also works as dijkastra
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V,INT_MAX);
    dist[S]=0;
    queue<pair<int,int>> q;
    q.push({S,0});
    while(!q.empty()){
        int node=q.front().first;
        int distance=q.front().second;
        q.pop();
        
        for(auto i:adj[node]){
            if(i[1]+distance<dist[i[0]]){
                dist[i[0]]=i[1]+distance;
                q.push({i[0],dist[i[0]]});
            }
        }
    }
    
    for(int i=0;i<V;i++){
        if(dist[i]==INT_MAX) dist[i]=-1;
    }
    
    return dist;
}

//Dijkstra using priority queue
//using priority queue instead of queue can reduce TC
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V,INT_MAX);
    dist[S]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,S});
    while(!pq.empty()){
        int node=pq.top().second;
        int distance=pq.top().first;
        pq.pop();
        
        for(auto i:adj[node]){
            if(i[1]+distance<dist[i[0]]){
                dist[i[0]]=i[1]+distance;
                pq.push({dist[i[0]],i[0]});
            }
        }
    }
    return dist;
}
//TC is O(E*logV)

//by using set
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V,INT_MAX);
    dist[S]=0;
    set<pair<int,int>> st;
    st.insert({0,S});
    while(!st.empty()){
        auto top=*(st.begin());
        int node=top.second;
        int distance=top.first;
        st.erase(top);
        
        for(auto i:adj[node]){
            if(i[1]+distance<dist[i[0]]){
                
                if(dist[i[0]]!=INT_MAX)
                    st.erase({dist[i[0]],i[0]});
                
                dist[i[0]]=i[1]+distance;
                st.insert({dist[i[0]],i[0]});
            }
        }
    }
    
    for(int i=0;i<V;i++){
        if(dist[i]==INT_MAX) dist[i]=-1;
    }
    
    return dist;
}