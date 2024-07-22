//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int i=0;
        int maxi=0;
        vector<int> vis(256,-1);
        for(int j=0;j<s.size();j++){
            if(vis[s[j]]>=i){
                i=vis[s[j]]+1;
            }
            vis[s[j]]=j;
            maxi=max(maxi,j-i+1);
        }

        return maxi;
    }
};