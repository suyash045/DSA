//Frog jump
#include<bits/stdc++.h>
using namespace std;

//Memoization solution
class Solution {
  public:
    int f(int n,vector<int>& height,vector<int> &dp){
        if(n==0) return dp[0]=0;
        if(n==1) return dp[1]=abs(height[0]-height[1]);
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=min(abs(f(n-1,height,dp)+abs(height[n]-height[n-1])),abs(f(n-2,height,dp)+abs(height[n]-height[n-2])));
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        return f(n-1,height,dp);
    }
};

//Tabulation Solution
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        dp[0]=0;
        dp[1]=abs(height[0]-height[1]);
        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-1]+abs(height[i]-height[i-1]),dp[i-2]+abs(height[i]-height[i-2]));
        }
        return dp[n-1];
    }
};

//space optimization solution
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        if(n==1) return 0;
        int prev2=0;
        int prev1=abs(height[0]-height[1]);
        for(int i=2;i<n;i++){
            int curr=min(prev1+abs(height[i]-height[i-1]),prev2+abs(height[i]-height[i-2]));
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};