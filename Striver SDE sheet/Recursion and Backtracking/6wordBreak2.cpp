#include<bits/stdc++.h>
using namespace std;

bool inDict(string s,vector<string> &dictionary){
    for(auto i:dictionary){
        if(i==s) return true;
    }
    return false;
}
void f(int ind,int n,string s,vector<string> &dictionary,vector<string> &ans){
    if(inDict(s.substr(ind-1,s.size()-(ind-1)),dictionary)){
        ans.push_back(s);
    }
    if(ind>=n){
        return;
    }

    for(int i=ind;i<n;i++){
        if(inDict(s.substr(ind-1,i-(ind-1)),dictionary)){
            s.insert(i," ");
            f(i+2,s.size(),s,dictionary,ans);
            s.erase(i,1);
        }
    }

    return;
}
vector<string> wordBreak(string &s, vector<string> &dictionary){
    vector<string> ans;
    f(1,s.size(),s,dictionary,ans);
    return ans;
}