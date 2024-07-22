#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) {
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        
        if(M[a][b]==1){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    
    int ans=s.top();        
    bool x=1;
    for(int i=0;i<n;i++){
        if(M[ans][i]==1){
            x=0;
        }
        if(M[i][ans]==0 && i!=ans){
            x=0;
        }
    }
    if(x==1) return ans;
    return -1;
}