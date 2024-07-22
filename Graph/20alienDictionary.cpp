#include<bits/stdc++.h>
using namespace std;

//create map by traversing in dict then apply topo sort
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        unordered_map<char,set<char>> adj;
        unordered_map<char,int> indegree;
        for(int i=1;i<N;i++){
            int k=0,l=0;
            while(k<dict[i].size() && l<dict[i-1].size()){
                if(dict[i][k]!=dict[i-1][l]) break;
                l++;
                k++;
            }
            if(k==dict[i].size() || l==dict[i-1].size()) continue;
            if(adj[dict[i-1][l]].find(dict[i][k])==adj[dict[i-1][l]].end()){
                adj[dict[i-1][l]].insert(dict[i][k]);
                indegree[dict[i][k]]++;
            }
        }
        
        queue<char> q; 
        for(char i='a';i<'a'+K;i++){
            if(indegree[i]==0) q.push(i);
        }
        string ans="";
        while(!q.empty()){
            char front=q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto i:adj[front]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        
        return ans;
    }
};