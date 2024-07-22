#include<bits/stdc++.h>
using namespace std;

//Normal recursion has TC exponential and SC O(n+m)

//Memoization
class Solution {
public:
    bool f(int n,int m,string &s, string &p,vector<vector<int>> &dp){
        if(n<0 && m<0) return true;
        if(n<0 && m>=0){
            for(int i=0;i<=m;i++){
                if(p[i]!='*') return false; 
            }
            return true;
        }
        if(n>=0 && m<0) return false;
        
        if(dp[n][m]!=-1) return dp[n][m];

        if(s[n]==p[m] || p[m]=='?') return dp[n][m]=f(n-1,m-1,s,p,dp);
        if(p[m]=='*') return dp[n][m]=f(n-1,m,s,p,dp) || f(n,m-1,s,p,dp);
        
        return dp[n][m]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};

//Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,0));
        
        for(int i=1;i<m+1;i++){
            bool flag=true;
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*') flag=false;
            }
            dp[0][i]=flag;
        }
        dp[0][0]=true;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
                else dp[i][j]=false;
            }
        }

        return dp[n][m];
    }
};

//Space Optimization
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<bool> prev(m+1,0),curr(m+1,0);
        
        for(int i=1;i<m+1;i++){
            bool flag=true;
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*') flag=false;
            }
            curr[i]=prev[i]=flag;
        }
        prev[0]=true;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j]=prev[j-1];
                else if(p[j-1]=='*') curr[j]=(prev[j] || curr[j-1]);
                else curr[j]=false;
            }
            prev=curr;
        }

        return prev[m];
    }
};
