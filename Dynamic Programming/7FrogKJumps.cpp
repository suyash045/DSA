//Q. Previous que if frog taking i+1,i+2,i+3,...,i+k jumps.

#include<bits/stdc++.h>
using namespace std;

//Memoization
int solve(int n,int k,vector<int> &height,vector<int> &dp){
    if(n==0) return 0;
    if(n==1) return abs(height[0]-height[1]);

    int mini=INT_MAX;
    int u=-1;
    for(int i=1;i<=k;i++){
        if((n-i)<0) continue; 
        int a;
        if(dp[n-i]!=-1){
            a=dp[n-i];
        }else{
            dp[n-i]=solve(n-i,k,height,dp);
            a=dp[n-i];
        }
        if(a<mini){
            mini=a;
            u=n-i;
        }
    }
    int energy=mini+abs(height[n]-height[u]);
    return dp[n]=energy;
}
//TC is O(n*k)
//SC is O(n)+O(n)

//Tabulation
int solve1(int n,int k,vector<int> &height){
    vector<int> dp1(n-1,-1);
    dp1[0]=0;
    dp1[1]=abs(height[0]-height[1]);

    for(int i=2;i<=n;i++){
        int mini=INT_MAX;
        int u=-1;
        for(int j=1;j<=k;j++){
            if(i-j>=0 && mini>dp1[i-j]){
                mini=dp1[i-j];
                u=i-j;
            }
        }
        dp1[i]=mini+abs(height[i]-height[u]);
    }
    return dp1[n];
}
//TC is O(n+k)
//SC is O(n)

int main(){
    int n=4;
    int k=2;
    vector<int> height{10,20,30,10};
    vector<int> dp(n,-1);

    cout<<solve(n-1,k,height,dp)<<endl;
    cout<<solve1(n-1,k,height)<<endl;

return 0;
}


