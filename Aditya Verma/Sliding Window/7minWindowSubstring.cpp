//https://leetcode.com/problems/minimum-window-substring/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();

        unordered_map<char,int> m;

        for(int i=0;i<t.size();i++) m[t[i]]++;

        int i=0,j=0;
        int start=0;
        int count=t.size(); 
        int mini=INT_MAX;

        while(j<n){
            if(count!=0){
                if(m[s[j++]]-- > 0 ) count--;
            }
            while(count==0){
                if(mini>j-i){
                    mini=j-i;
                    start=i;
                }
                if(m[s[i++]]++ >= 0) count++;
            }
        }
        if(mini==INT_MAX) return ""; 
        return s.substr(start,mini);
    }
};