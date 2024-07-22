//Capture surrounded regions
#include<bits/stdc++.h>
using namespace std;

//Traverse through islands on boundary. Capture remaining islands
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q; 
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        for(int i=1;i<m-1;i++){
            if(board[0][i]=='O'){
                vis[0][i]=1;
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int l=0;l<4;l++){
                int newx=x+dx[l];
                int newy=y+dy[l];
                if(newx>=0 && newx<n && newy>=0 && newy<m){
                    if(board[newx][newy]=='O' && !vis[newx][newy]){
                        q.push({newx,newy});
                        vis[newx][newy]=1;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j]='X'; 
            }
        }
    }
};