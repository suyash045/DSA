#include<bits/stdc++.h>
using namespace std;

//Normal recursion solution : TC is 2^(m*n)
//                            SC is O(path length) which is O(n-1+m-1)

//Memoization
class Solution {
public:
    int f(int m,int n,vector<vector<int>> &dp){
        if(m==0 && n==0){ 
            return 1;
        }
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=f(m-1,n,dp)+f(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,dp);
    }
};
//TC is O(n*m)
//SC is O(n-1+m-1)used for recursion stack space + O(n*m)used for dp vector

//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1<0) dp[i][j]=1;
                else if(j-1<0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
//TC is O(n*m)
//SC is O(n*m)

//Space optimization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        int left=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]=dp[j]+left;
                left=dp[j];
            }
            left=1;
        }
        return dp[n-1];
    }
};
//TC is O(n*m)
//SC is O(n)

//Another solution with less TC & SC
//We have to go down m-1 times and left n-1 times. Total turns are N = n-1+m-1.
//hence ans is Ncr = N! / ((N-r)!)(r!) where r = n-1 or m-1
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m-1+n-1;
        int r=m-1;
        double ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(N-r+i)/i;
        }
        return (int)ans;
    }
};
//TC is O(m-1) or O(n-1)
//SC is O(1)
