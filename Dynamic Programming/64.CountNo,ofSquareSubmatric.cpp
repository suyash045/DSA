#include<bits/stdc++.h>
using namespace std;

//In dp array element dp[i][j] gives no. of squares formed in which element is at bottom right.
// Matrix :
// 1 1 1 1 1 
// 1 1 1 1 1 
// 1 1 1 1 1 
// dp :
// 1 1 1 1 1 
// 1 2 2 2 2 
// 1 2 3 3 3 

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));

        int sum=0;
        for(int i=0;i<n;i++){
            dp[i][0]=matrix[i][0];
            sum+=dp[i][0];
        }
        for(int j=1;j<m;j++){
            dp[0][j]=matrix[0][j];
            sum+=dp[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0) dp[i][j]=0;
                else dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                sum+=dp[i][j];
            }
        }

        return sum;
    }
};

