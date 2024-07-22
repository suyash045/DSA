#include<bits/stdc++.h>
using namespace std;


bool isSafe(int node,int n,bool graph[101][101],int col,vector<int> color){
    for(int i=0;i<n;i++){
        if(i!=node && graph[i][node]==1 && color[i]==col){
            return false;
        }
    }
    
    return true;
}
bool f(int node,int m,int n,bool graph[101][101],vector<int> color){
    if(node==n) return true;
    
    for(int i=1;i<=m;i++){
        if(isSafe(node,n,graph,i,color)){
            color[node]=i;
            bool temp=f(node+1,m,n,graph,color);
            if(temp) return true;
            color[node]=0;
        }
    }
    
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n,0);
    return f(0,m,n,graph,color);
}