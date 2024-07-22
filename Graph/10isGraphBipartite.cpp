#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int node,vector<int> &vis,vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            int temp=vis[front];

            for(auto i:graph[front]){
                if(vis[i]==0){
                    q.push(i);
                    if(temp==1) vis[i]=2;
                    else vis[i]=1;
                }
                else if(vis[i]==temp){
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bool temp=bfs(i,vis,graph);
                if(temp==0) return 0;
            }
        }
        return 1;
    }
};