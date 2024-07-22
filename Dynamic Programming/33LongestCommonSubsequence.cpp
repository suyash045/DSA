#include<bits/stdc++.h>
using namespace std;

//f(n) gives longest common subsequence till n
//normal recursion has TC O(2^n * 2^m)

//Memoization
class Solution {
public:
    int f(int n,int m,string &text1, string &text2,vector<vector<int>> &dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=0) return dp[n][m];

        if(text1[n]==text2[m]) return dp[n][m]=1+f(n-1,m-1,text1,text2,dp);
        
        return dp[n][m]=max(f(n,m-1,text1,text2,dp),f(n-1,m,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n,vector<int> (m,0));
        return f(n-1,m-1,text1,text2,dp);
    }
};
//TC is O(n*m)
//TC is O(n+m)+O(n*m)

//(optional) In Tabulation we use 1 base indexing to avoid complex base cases
//Tabulation
//Ex. text1 = "abcde", text2 = "ace" 
//dp array:
//  a b c d e 
//a 1 1 1 1 1 
//c 1 1 2 2 2 
//e 1 1 2 2 3 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};

//Space Optimization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<int> curr(m+1,0),prev(m+1,0);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return curr[m];
    }
};

//DP array is 
//(text1="abcde", text2="bdqek")
//    b d q e k
//  0 0 0 0 0 0
//a 0 0 0 0 0 0
//b 0 1 1 1 1 1 
//c 0 1 1 1 1 1 
//d 0 1 2 2 2 2 
//e 0 1 2 2 3 3

//dp[5][5] gives lcs
//Similarly dp[4][2] gives lcs of "abcd" and "bd".
