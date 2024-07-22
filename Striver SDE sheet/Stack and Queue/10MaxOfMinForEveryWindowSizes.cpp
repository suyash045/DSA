#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    stack<int> s;
    stack<int> s1;
    int prevSmall[n];
    int nextSmall[n];

    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(s.empty()) prevSmall[i]=-1;
        else prevSmall[i]=s.top();
        s.push(i);
    }

    for(int i=n-1;i>=0;i--){
        while(!s1.empty() && a[s1.top()]>=a[i]){
            s1.pop();
        }
        if(s1.empty()) nextSmall[i]=n;
        else nextSmall[i]=s1.top();
        s1.push(i);
    }

    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++){
        int len=nextSmall[i]-prevSmall[i];
        ans[len-2]=max(ans[len-2],a[i]);
    }

    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }

    return ans;
} 