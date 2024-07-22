#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==1) return 1;
        map<char,int> m;
        m[s[0]]=0;
        int l=0;
        int maxi=0;
        for(int r=1;r<n;r++){
            if(m.find(s[r])!=m.end() && m[s[r]]>=l){
                l=m[s[r]]+1;
                maxi=max(maxi,r-l+1);
            }
            else{
                maxi=max(maxi,r-l+1);
            }
            m[s[r]]=r;
        }
        return maxi;
    }
};