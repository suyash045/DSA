#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()) return -1;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            if(haystack.substr(i,needle.size())==needle) return i;
        }
        return -1;
    }
};

//using z-function
//In z array element is longest substring which is prefix of whole string.
//Ex. source="baabaa" ,tar="aab"
//get Z array of "aab$baabaa" 
//                0100031021
class Solution {
public:
    vector<int> getZ(string str){
        int n=str.size();
        vector<int> z(n,0);
        int L,R=0,k;
        for(int i=1;i<n;i++){
            if(R<i){
                L=R=i;
                while(R<n && str[R-L]==str[R]) R++;
                z[i]=R-L;
                R--; 
            }
            else{
                k=i-L;
                if(z[k]<R-i+1) z[i]=z[k];
                else{
                    L=i;
                    while(R<n && str[R-L]==str[R]) R++;
                    z[i]=R-L;
                    R--;
                }
            }
        }
        return z;
    }
    int strStr(string haystack, string needle) {
        string combined=needle+'$'+haystack;

        vector<int> z=getZ(combined);

        for(int i=0;i<z.size();i++){
            if(z[i]==needle.size()){
                return i-needle.size()-1;
            }
        }

        return -1;
    }
};

//KMP algo
//Ex. tar="ababc" ,source="abcababc"
//for target write lps array
//tar="ababc"
//lps  00120    
class Solution {
public:
    vector<int> getLPS(string &needle){
        int m=needle.size();
        int len=0;
        int j=1;
        vector<int> lps(m,0);
        while(j<m){
            if(needle[len]==needle[j]){
                len++;
                lps[j]=len;
                j++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[j]=0;
                    j++;
                }
            }
        }
        return lps;
    }
    vector<int> KMP(string &haystack, string &needle,vector<int> &lps){
        int n=haystack.size();
        int m=needle.size();
        vector<int> ans;
        int i=0,j=0;
        while((n-i)>=(m-j)){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m){
                    ans.push_back(i-j);
                    j=lps[j-1];
                }
            else if(i<n && haystack[i]!=needle[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
    int strStr(string haystack, string needle) {
        vector<int> lps=getLPS(needle);
        vector<int> indices=KMP(haystack,needle,lps);
        if(indices.size()==0) return -1;
        return indices[0];
    }
};