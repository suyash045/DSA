#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(i==0){
                ans=strs[0];
                continue;
            }
            int j=0;
            string temp="";
            while(j<strs[i].size() && strs[i][j]==ans[j]){
                temp.push_back(ans[j]);
                j++;
            }
            ans=temp;
        }

        return ans;
    }
};

//Optimal
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]) return ans;
            ans.push_back(first[i]);
        }

        return ans;
    }
};