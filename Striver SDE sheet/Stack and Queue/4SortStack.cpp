#include<bits/stdc++.h>
using namespace std;

void Sort(stack<int> &s){
    if(s.size()==1) return;
    
    int temp=s.top();
    s.pop();
    
    Sort(s);
    
    stack<int> s2;
    while(!s.empty() && temp<s.top()){
        s2.push(s.top());
        s.pop();
    }
    s.push(temp);
    while(!s2.empty()){
        s.push(s2.top());
        s2.pop();
    }
    
    return;
}