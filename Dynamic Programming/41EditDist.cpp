#include<bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int f(int n,int m,string &s1, string &s2,vector<vector<int>> &dp){
        if(n<0) return m+1;
        if(m<0) return n+1;
        if(dp[n][m]!=0) return dp[n][m];

        if(s1[n]==s2[m]) return f(n-1,m-1,s1,s2,dp);

        int insert=1+f(n,m-1,s1,s2,dp);
        int delete1=1+f(n-1,m,s1,s2,dp);
        int replace=1+f(n-1,m-1,s1,s2,dp);

        return dp[n][m]=min(insert,min(delete1,replace));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        return f(n-1,m-1,word1,word2,dp);
    }
};

//Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<n+1;i++) dp[i][0]=i;
        for(int i=0;i<m+1;i++) dp[0][i]=i;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int insert=1+dp[i][j-1];
                    int delete1=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min(insert,min(delete1,replace));
                }
            }
        }
        return dp[n][m];
    }
};

//Space Optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
      
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=0;i<m+1;i++) curr[i]=prev[i]=i;

        for(int i=1;i<n+1;i++){
            curr[0]=i;
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
                else{
                    int insert=1+curr[j-1];
                    int delete1=1+prev[j];
                    int replace=1+prev[j-1];
                    curr[j]=min(insert,min(delete1,replace));
                }
            }
            prev=curr;
        }
        return curr[m];
    }
};

