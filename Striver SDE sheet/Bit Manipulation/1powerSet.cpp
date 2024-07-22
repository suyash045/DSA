#include<bits/stdc++.h>
using namespace std;

//Power set
//1<<n is equal to 2 raise to n
//for checking 2nd last bit of num=11010 is set or not, we do if(num&(1<<2)) 
//Ex. "abc"
//2 raise to 3 = 8
//  abc
//0 000
//1 001
//2 010
//3 011
//4 100
//5 101
//6 110
//7 111
//if there is 1 take the respective char
vector<string> AllPossibleStrings(string s){
    int n=s.size();
    vector<string> ans;
    for(int i=0;i<(1<<n);i++){
        string sub="";
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sub+=s[j];
            }
        }
        if(sub.size()>0) ans.push_back(sub);
    }
    sort(ans.begin(),ans.end());
    return ans;
}