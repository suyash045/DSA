#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int count=0;
        while(!q.empty()){
            bool flag=0;
            int size=q.size();

            for(int k=0;k<size;k++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(int l=0;l<4;l++){
                    int newx=x+dx[l];
                    int newy=y+dy[l];

                    if(newx>=0 && newx<n && newy>=0 && newy<m){
                        if(grid[newx][newy]==1 && !vis[newx][newy]){
                            flag=1;
                            vis[newx][newy]=1;
                            q.push({newx,newy});
                        }
                    }
                }

            }
            if(flag==1) count++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }

        return count;
    }
};