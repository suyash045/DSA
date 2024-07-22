#include<bits/stdc++.h>
using namespace std;

//characters in substring should be consecutive
//DP array will be 
//(s1="abcd", s2="abwd")
//    a b w d 
//  0 0 0 0 0 
//a 0 1 0 0 0 
//b 0 0 2 0 0 
//c 0 0 0 0 0 
//d 0 0 0 0 1

//Tabulation
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }    
                else dp[i][j]=0;
            }
        }
        
        return ans;
    }
};

//space optimization
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ans=0;
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(S1[i-1]==S2[j-1]){
                    curr[j]=1+prev[j-1];
                    ans=max(ans,curr[j]);
                }    
                else curr[j]=0;
            }
            prev=curr;
        }
        
        return ans;
    }
};
