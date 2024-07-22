#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    dist[0][0]=0;

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
    pq.push({0,{0,0}});

    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    while(!pq.empty()){
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        int d=pq.top().first;
        pq.pop();

        for(int l=0;l<4;l++){
            int nx=x+dx[l];
            int ny=y+dy[l];

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(dist[nx][ny]>max(dist[x][y],abs(heights[nx][ny]-heights[x][y]))){
                    dist[nx][ny]=max(dist[x][y],abs(heights[nx][ny]-heights[x][y]));
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
    }

    return dist[n-1][m-1];
}