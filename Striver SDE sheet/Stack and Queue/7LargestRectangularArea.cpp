#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int nextSmall[n];
        int prevSmall[n];

        stack<pair<int,int>> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first>=heights[i]) s.pop();
            if(s.empty()){
                nextSmall[i]=n;
            }
            else{
                nextSmall[i]=s.top().second;
            }
    
            s.push({heights[i],i});
        }

        stack<pair<int,int>> s1;
        for(int i=0;i<n;i++){
            while(!s1.empty() && s1.top().first>heights[i]) s1.pop();
            if(s1.empty()){
                prevSmall[i]=-1;
            }
            else{
                prevSmall[i]=s1.top().second;
            }
    
            s1.push({heights[i],i});
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int area=(nextSmall[i]-prevSmall[i]-1)*heights[i];
            ans=max(ans,area);
        }
        return ans;
    }
};

//
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        int ans=0;
        for(int i=0;i<n+1;i++){
            while(!s.empty() && (i==n || heights[s.top()]>heights[i])){
                int height=heights[s.top()];
                s.pop();
                int leftSmall=-1;
                if(!s.empty()) leftSmall=s.top();
                int area=(i-leftSmall-1)*height;
                ans=max(ans,area);
            }   
            s.push(i);
        }

        return ans;
    }
};
//TC is O(n) + O(n)
//SC is O(n)