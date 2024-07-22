//https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        int maxi=-1;
        unordered_map<char,int> m;
        m[s[i]]++;
        while(j<=n){
            if(m.size()==k){
                maxi=max(maxi,j-i+1);
                j++;
                if(j==n) break;
                m[s[j]]++;
            }
            else if(m.size()>k){
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }
            else{
                j++;
                if(j==n) break;
                m[s[j]]++;
            }
        }
        return maxi;
    }
};