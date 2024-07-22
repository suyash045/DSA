#include<bits/stdc++.h>
using namespace std;

//We calculated largest area of histogram while traversing through the rows
class Solution {
public:
    int largestArea(vector<int> &heights,int m){
        //for creating prev smaller
        vector<int> prevSmall(m,-1);
        stack<int> st;
        for(int i=0;i<m;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();

            if(st.empty()) prevSmall[i]=-1;
            else prevSmall[i]=st.top();

            st.push(i);
        }

        //for creating next smaller
        vector<int> nextSmall(m,-1);
        stack<int> st1;
        for(int i=m-1;i>=0;i--){
            while(!st1.empty() && heights[st1.top()]>=heights[i]) st1.pop();

            if(st1.empty()) nextSmall[i]=m;
            else nextSmall[i]=st1.top();

            st1.push(i);
        }

        int maxi=0;
        for(int i=0;i<m;i++){
            int area=(nextSmall[i]-prevSmall[i]-1)*heights[i];
            maxi=max(maxi,area);
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') heights[j]=heights[j]+1;
                else heights[j]=0;
            }

            //TC of largestArea fn is O(n) because we are using monotonic stack
            maxi=max(maxi,largestArea(heights,m));
        }

        return maxi;
    }
};
//TC is O(n*(n+m))
//SC is O(n) space used in height vector + stack