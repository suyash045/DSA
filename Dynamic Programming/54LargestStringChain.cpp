#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool compare(int i,int j,string s,string t){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;

        if(s[i]==t[j]) return compare(i+1,j+1,s,t);
        else return compare(i+1,j,s,t);
    }
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i].size()==words[j].size()+1 && compare(0,0,words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};
//TC is O(n^2 * l) where l is max length of string 
//SC is O(nlogn)for sorting + O(n)