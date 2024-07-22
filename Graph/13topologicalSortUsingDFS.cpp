#include<bits/stdc++.h>
using namespace std;

//Topological sort: for every directed edge u -> v,  u must come before v in the ordering.
class Solution
{
	public:
	void dfs(int node, vector<int> adj[],vector<bool> &vis,stack<int> &st){
	    vis[node]=1;
	    for(auto i:adj[node]){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> vis(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};