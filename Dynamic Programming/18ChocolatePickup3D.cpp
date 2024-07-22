#include<bits/stdc++.h>
using namespace std;
//Normal recursion sol has TC O(3^n * 3^n) and SC O(n)

//Memoization
class Solution {
  public:
    int f(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e7;
        if(i==n-1){ 
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxi=-1e7;
        for(int d1=-1;d1<2;d1++){
            for(int d2=-1;d2<2;d2++){
                int value=0;
                if(j1=j2) value=grid[i][j1];
                else value=grid[i][j1]+grid[i][j2];
                
                value+=f(i+1,j1+d1,j2+d2,n,m,grid,dp);
                
                maxi=max(maxi,value);
            }
        }
        
        return dp[i][j1][j2]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
        
        return f(0,0,m-1,n,m,grid,dp);
    }
};
//TC is O(n*m*m)*9
//TC is O(n*m*m)+O(n)

//Tabulation
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,0)));
        
        for(int i=n-1;i>=0;i++){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    if(i==n-1){
                        if(j1==j2) dp[i][j1][j2]=grid[i][j1];
                        else dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
                    } 
                    else{
                        int maxi=0;
                        int value=0;
                        if(j1==j2) value=grid[i][j1];
                        else value=grid[i][j1]+grid[i][j2];
                        
                        for(int dj1=(-1+j1);dj1<(2+j1);dj1++){
                            for(int dj2=(-1+j2);dj2<(2+j2);dj2++){
                                if(dj1>=0 && dj1<=(m-1) && dj2>=0 && dj2<=(m-1)){
                                    
                                    maxi=max(maxi,value+dp[i+1][dj1][dj2]);
                                }
                            }
                        }
                        dp[i][j1][j2]=maxi;
                    }
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};
//

//Space Optimization
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> front(m,vector<int> (m,0)),curr(m,vector<int> (m,0));
        
        for(int i=n-1;i>=0;i++){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    if(i==n-1){
                        if(j1==j2) curr[j1][j2]=grid[i][j1];
                        else curr[j1][j2]=grid[i][j1]+grid[i][j2];
                    } 
                    else{
                        int maxi=0;
                        int value=0;
                        if(j1==j2) value=grid[i][j1];
                        else value=grid[i][j1]+grid[i][j2];
                        
                        for(int dj1=(-1+j1);dj1<(2+j1);dj1++){
                            for(int dj2=(-1+j2);dj2<(2+j2);dj2++){
                                if(dj1>=0 && dj1<=(m-1) && dj2>=0 && dj2<=(m-1)){
                                    
                                    maxi=max(maxi,value+front[dj1][dj2]);
                                }
                            }
                        }
                        curr[j1][j2]=maxi;
                    }
                }
            }
            front=curr;
        }
        
        return curr[0][m-1];
    }
};

