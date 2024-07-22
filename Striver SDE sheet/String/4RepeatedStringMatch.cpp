#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(b=="") return 0;
        int j=0;
        queue<int> q;
        while(j<a.size()){
            if(a[j]==b[0]) q.push(j);
            j++;
        }

        int cnt=0;
        while(!q.empty()){
            j=q.front();
            q.pop();
            cnt=0;
            for(int i=0;i<b.size();i++){
                if(a[j]!=b[i]) break;

                if(j==a.size()-1){
                    j=0;
                    cnt++;
                }
                else j++;
                if(i==b.size()-1){
                    if(j==0) return cnt;
                    return cnt+1;
                }
            }
        }
        return -1;
    }
};

//Errors are there for large testcases in below code 
//Rabin Karp algo 
//Use string hash
//Ex. aab = 97 * 31^2 + 97 * 31 + 98  where 97 and 98 are ASCII codes
class Solution {
public:
    int base=1e6;
    int rabinKarp(string source,string tar){
        int m=tar.size();
        int tarCode=0;
        int mult=1;
        for(int i=0;i<m;i++){
            tarCode=(tarCode*31+tar[i])%base;
            mult=(mult*31)%base;
        }
        int hash=0;
        for(int i=0;i<source.size();i++){
            hash=(hash*31+source[i])%base;
            if(i<m-1) continue;
            if(i>=m) hash=(hash-mult*source[i-m])%base;
            if(hash<0) hash+=base;
            if(hash==tarCode){
                if(tar==source.substr(i-m+1,m)){
                    return 1;
                }
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        if(b=="") return 0;
        if(b==a) return 1;
        int count=1;
        string temp=a;
        while(a.size()<b.size()){
            count++;
            a+=temp;
        } 

        if(a==b) return count;
        if(rabinKarp(a,b)!=-1) return count;
        if(rabinKarp(a+temp,b)!=-1) return count+1;
        return -1;
    }
};