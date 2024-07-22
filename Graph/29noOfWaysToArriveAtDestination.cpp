#include<bits/stdc++.h>
using namespace std;

//create ways array
#define ll long long
#define pll pair<ll,ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        unordered_map<ll,list<pll>> adj; 
        for(int i=0;i<roads.size();i++){
            ll u=roads[i][0];
            ll v=roads[i][1];
            ll t=roads[i][2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        
        vector<ll> time(n,LONG_MAX);
        time[0]=0;

        vector<ll> ways(n,0);
        ways[0]=1;

        priority_queue<pll,vector<pll>,greater<>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            ll node=pq.top().second;
            ll t=pq.top().first;
            pq.pop();

            for(auto i:adj[node]){
                if(time[i.first]>t+i.second){
                    time[i.first]=t+i.second;
                    pq.push({time[i.first],i.first});
                    ways[i.first]=ways[node];
                }
                else if(time[i.first]==t+i.second){
                    ways[i.first]=(ways[i.first]+ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};