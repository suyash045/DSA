#include<bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({A[N-1]+B[N-1],{N-1,N-1}});
    
    set<pair<int,int>> s;
    s.insert({N-1,N-1});
    
    vector<int> ans;
    for(int l=0;l<K;l++){
        pair<int,pair<int,int>> temp=pq.top();
        pq.pop();
        ans.push_back(temp.first);
        
        int i=temp.second.first;
        int j=temp.second.second;
        
        if(i-1>=0 && s.find({i-1,j})==s.end()){
            pq.push({A[i-1]+B[j],{i-1,j}});
            s.insert({i-1,j});
        }
        
        if(j-1>=0 && s.find({i,j-1})==s.end()){
            pq.push({A[i]+B[j-1],{i,j-1}});
            s.insert({i,j-1});
        }
    }
    return ans;
}