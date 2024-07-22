#include<bits/stdc++.h>
using namespace std;

//Sort meetings according to end time
int maxMeetings(int start[], int end[], int n){
    vector<pair<int,int>> m;
    for(int i=0;i<n;i++){
        m.push_back({end[i],start[i]});
    }
    
    sort(m.begin(),m.end());
    
    int time=0,cnt=0;
    for(auto i:m){
        if(i.second>time){
            cnt++;
            time=i.first;
        }
    }
    
    return cnt;
}