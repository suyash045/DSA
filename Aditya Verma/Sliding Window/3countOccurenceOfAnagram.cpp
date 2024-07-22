//https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int search(string pat, string txt) {
	    int n=pat.size();
	    int k=txt.size();
	    
	    int cnt=0;
	    vector<int> m1(26,0);
	    vector<int> m2(26,0);
	    for(int i=0;i<k;i++){
	        m1[pat[i]-'a']++;
	        m2[txt[i]-'a']++;
	    }
	    bool flag=1;
	    for(int i=0;i<26;i++){
	        if(m1[i]!=m2[i] && flag==1) flag=0;
	    }
	    if(flag==1) cnt++;
	    
	    for(int i=k;i<n;i++){
	        m1[pat[i-k]-'a']--;
	        m1[pat[i]-'a']++;
	        
	        flag=1;
    	    for(int i=0;i<26;i++){
    	        if(m1[i]!=m2[i] && flag==1) flag=0;
    	    }
    	    if(flag==1) cnt++;
	    }
	    return cnt;
	}

};