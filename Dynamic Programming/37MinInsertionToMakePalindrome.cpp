#include<bits/stdc++.h>
using namespace std;

//no. of minimum insertion=n-longest palindrome subsequence 
//for example : codingnijas -> codsajingnijasdoc ans=6

//Space Optimization
class Solution {
public:
    int LCS(string text1, string text2) {
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
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        return LCS(t,s);
    }
    int minInsertions(string s) {
        int n=s.length();
        return n-longestPalindromeSubseq(s);
    }
};