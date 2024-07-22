#include<bits/stdc++.h>
using namespace std;

//Max no. of operations are n+m
//Min no. of operations are n-lcs+m-lcs where lcs is length of longest common subsequence

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
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int lcs=LCS(word1,word2);
        return n+m-2*lcs;
    }
};