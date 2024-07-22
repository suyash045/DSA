#include<bits/stdc++.h>
using namespace std;

//Use kahn's algorithm
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto j:adj[i]) indegree[j]++;
    }
    
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }
    
    int cnt=0;
    while(!q.empty()){
        cnt++;
        int front=q.front();
        q.pop();
        
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    
    if(cnt==V) return 0;
    return 1;
}