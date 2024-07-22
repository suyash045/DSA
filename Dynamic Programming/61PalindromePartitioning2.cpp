#include<bits/stdc++.h>
using namespace std;

//max cuts are n-1


//Memoization
class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        if(s[i]!=s[j]) return 0;
        if(i==j || i+1==j) return 1;

        return isPalindrome(i+1,j-1,s);
    }
    int f(int i,int n,string &s,vector<int> &dp){
        if(i==n) return -1;
        if(dp[i]!=0) return dp[i];

        int mini=1e9;
        for(int k=i+1;k<=n;k++){
            int cuts=1e7;
            if(isPalindrome(i,k-1,s)) cuts=1+f(k,n,s,dp);
            mini=min(mini,cuts);
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        return f(0,n,s,dp);
    }
};
//TC is O(n^2)
//SC is O(n)+O(n)

//Tabulation
class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        if(s[i]!=s[j]) return 0;
        if(i==j || i+1==j) return 1;

        return isPalindrome(i+1,j-1,s);
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=-1;

        for(int i=n-1;i>=0;i--){
            int mini=1e9;
            for(int k=i+1;k<=n;k++){
                int cuts=1e7;
                if(isPalindrome(i,k-1,s)) cuts=1+dp[k];
                mini=min(mini,cuts);
            }
            dp[i]=mini;
        }
        return dp[0];
    }
};

//Space Optimization
