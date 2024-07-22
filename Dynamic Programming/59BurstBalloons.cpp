#include<bits/stdc++.h>
using namespace std;

//Memoization
//We apply logic in reverse order 
//Ex. {3,1,5,8}
//{8} -> {3,8} -> {3,5,8} -> {3,1,5,8}
//((3(1)5)8) but write code in reverse order.
class Solution {
public:
    int f(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
        if(j<i) return 0;
        if(dp[i][j]!=0) return dp[i][j];

        int maxi=0;
        for(int k=i;k<=j;k++){
            int coins=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            maxi=max(maxi,coins);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        return f(1,n-2,nums,dp);
    }
};
//TC is O(n^3)
//SC is O(n)+O(n^2)

//Tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n,0));

        for(int i=n-2;i>=1;i--){
            for(int j=1;j<=n-2;j++){
                if(j<i) continue;

                int maxi=0;
                for(int k=i;k<=j;k++){
                    int coins=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,coins);
                }
                dp[i][j]=maxi;
            }
        }

        return dp[1][n-2];
    }
};

//Space Optimization
