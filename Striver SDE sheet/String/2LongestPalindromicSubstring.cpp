#include<bits/stdc++.h>
using namespace std;

//here dp array is
//Ex. xacdcaz
//    0 1 2 3 4 5 6
// 0  1 0 0 0 0 0 0
// 1  0 1 0 0 0 0 0
// 2  0 0 1 0 0 0 0
// 3  0 0 0 1 0 0 0
// 4  0 0 1 0 1 0 0
// 5  0 1 0 0 0 1 0
// 6  0 0 0 0 0 0 1
//Here dp array itself says palindrome or not. We don't have to run separate loop.
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=1,start=0,end=0;
        vector<vector<bool>> dp(n,vector<bool> (n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            for(int j=0;j<i;j++){
               if(s[i]==s[j] && (i-j<=2 || (dp[i-1][j+1] && dp[i-1][i-1]))){
                    dp[i][j]=true;
                    if(i-j+1>maxLen){
                        maxLen=i-j+1;
                        start=j,end=i;
                    }
                }
            }
        }

        return s.substr(start,end-start+1);
    }
};