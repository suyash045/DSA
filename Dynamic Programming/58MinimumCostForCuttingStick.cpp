#include<bits/stdc++.h>
using namespace std;
//Memoization
class Solution {
public:
    int f(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int mini=1e9;
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int noCuts=cuts.size();
        vector<vector<int>> dp(noCuts+1,vector<int> (noCuts+1,-1));
        return f(1,noCuts-2,cuts,dp);
    }
};
//TC is O(m^3)
//SC is O(m)+O(m^2)

//Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int noCuts=cuts.size();
        vector<vector<int>> dp(noCuts+2,vector<int> (noCuts+2,0));

        for(int i=noCuts-2;i>=1;i--){
            for(int j=1;j<=noCuts-2;j++){
                if(i>j) continue;

                int mini=1e9;
                for(int k=i;k<=j;k++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }        

        return dp[1][noCuts-2];
    }
};

//Space Optimization

