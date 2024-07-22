#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int tot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) tot++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(tot==0) return 0;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int k=q.size();
            while(k>0){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                for(int l=0;l<4;l++){
                    int ni=i+dr[l];
                    int nj=j+dc[l];
                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1){
                        q.push({ni,nj});
                        tot--;
                        grid[ni][nj]=2;
                    }
                }

                k--;
            }
        }
        if(tot>0) return -1;
        return cnt-1;
    }
};