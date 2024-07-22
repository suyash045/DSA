#include<bits/stdc++.h>
using namespace std;

//Use dijkstra
//Instead of priority queue we can also use queue
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0]==1) return -1;
    int n=grid.size();
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    dist[0][0]=0;

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
    pq.push({0,{0,0}});

    int dx[]={-1,-1,-1,0,1,1,1,0};
    int dy[]={-1,0,1,1,1,0,-1,-1};
    while(!pq.empty()){
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        int d=pq.top().first;
        pq.pop();

        for(int l=0;l<8;l++){
            int nx=x+dx[l];
            int ny=y+dy[l];

            if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                if(dist[nx][ny]>d+1){
                    dist[nx][ny]=d+1;
                    pq.push({d+1,{nx,ny}});
                }
            }
        }
    }

    if(dist[n-1][n-1]==INT_MAX) return -1;
    return dist[n-1][n-1]+1;
}