#include<bits/stdc++.h>
using namespace std;

//Recursion has TC O(2^n * 2^m) and SC O(n+m)

//Memoization
class Solution {
public:
    int f(int n,int m,string s1,string s2,vector<vector<int>> &dp){
        if(m<0) return 1;
        if(n<0) return 0;
        if(dp[n][m]!=0) return dp[n][m];

        if(s1[n]==s2[m]) return dp[n][m]=f(n-1,m-1,s1,s2,dp)+f(n-1,m,s1,s2,dp);
        else return dp[n][m]=f(n-1,m,s1,s2,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int> (m,0));
        return f(n-1,m-1,s,t,dp);
    }
};

//if we get runtime error try using long long or double in dp array
//Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<double>> dp(n+1,vector<double> (m+1,0));
        for(int i=0;i<n+1;i++) dp[i][0]=1;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};

//Space Optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> prev(m+1,0),curr(m+1,0);
        prev[0]=curr[0]=1;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1]+prev[j];
                else curr[j]=prev[j];
            }
            prev=curr;
        }
        return (int)curr[m];
    }
};

//Further space optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> prev(m+1,0);
        prev[0]=1;

        for(int i=1;i<n+1;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]) prev[j]=prev[j-1]+prev[j];
            }
        }
        return (int)prev[m];
    }
};
