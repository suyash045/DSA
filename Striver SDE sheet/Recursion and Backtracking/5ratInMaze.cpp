#include<bits/stdc++.h>
using namespace std;

void f(int row,int col,vector<vector<int>> &m,int n,vector<vector<int>> vis,string temp,vector<string> &ans){
    if(row==n-1 && col==n-1) ans.push_back(temp);
    
    if(row-1>=0 && m[row-1][col]==1 && vis[row-1][col]==0){
        vis[row-1][col]=1;
        f(row-1,col,m,n,vis,temp+'U',ans);
        vis[row-1][col]=0;
    }
    
    if(row+1<n && m[row+1][col]==1 && vis[row+1][col]==0){
        vis[row+1][col]=1;
        f(row+1,col,m,n,vis,temp+'D',ans);
        vis[row+1][col]=0;
    }
    
    if(col-1>=0 && m[row][col-1]==1 && vis[row][col-1]==0){
        vis[row][col-1]=1;
        f(row,col-1,m,n,vis,temp+'L',ans);
        vis[row][col-1]=0;
    }
    
    if(col+1<n && m[row][col+1]==1 && vis[row][col+1]==0){
        vis[row][col+1]=1;
        f(row,col+1,m,n,vis,temp+'R',ans);
        vis[row][col+1]=0;
    }
    return;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans; 
    if(m[0][0]==0 || m[n-1][n-1]==0) return ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
    vis[0][0]=1;
    f(0,0,m,n,vis,"",ans);
    return ans;
}

//Smaller code
void f(int i,int j,vector<vector<int>> &m,int n,vector<vector<int>> vis,string temp,vector<string> &ans,int dr[],int dc[]){
    if(i==n-1 && j==n-1) ans.push_back(temp);
    
    string dir="URDL";
    for(int k=0;k<4;k++){
        int nexti=i+dr[k];
        int nextj=j+dc[k];
        
        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && m[nexti][nextj]==1 && vis[nexti][nextj]==0){
            vis[nexti][nextj]=1;
            f(nexti,nextj,m,n,vis,temp+dir[k],ans,dr,dc);
            vis[nexti][nextj]=0;
        }
    }
    
    return;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans; 
    if(m[0][0]==0 || m[n-1][n-1]==0) return ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
    vis[0][0]=1;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    f(0,0,m,n,vis,"",ans,dr,dc);
    return ans;
}