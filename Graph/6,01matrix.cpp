#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        vector<vector<int>> ans(n,vector<int> (m,0));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int d=q.front().second;
            q.pop();

            ans[x][y]=d;

            for(int l=0;l<4;l++){
                int newx=x+dx[l];
                int newy=y+dy[l];
                if(newx>=0 && newx<n && newy>=0 && newy<m){
                    if(mat[newx][newy]==1 && !vis[newx][newy]){
                        q.push({{newx,newy},d+1});
                        vis[newx][newy]=1;
                    }
                }
            }
        }

        return ans;
    }
};