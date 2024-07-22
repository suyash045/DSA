#include<bits/stdc++.h>
using namespace std;

//Memoization
int f(int i,int j,bool isTrue,string & exp,vector<vector<vector<int>>> &dp){
    if (i == j) {
        if(isTrue) return exp[i]=='T';
        else return exp[i]=='F';
    }
    if(dp[i][j][isTrue]!=0) return dp[i][j][isTrue];
    
    int ways=0;
    for(int k=i+1;k<=j-1;k=k+2){
        int LT=f(i,k-1,1,exp,dp);
        int RT=f(k+1,j,1,exp,dp);
        int LF=f(i,k-1,0,exp,dp);
        int RF=f(k+1,j,0,exp,dp);

        int temp=0;
        if(exp[k]=='&'){
            if(isTrue) temp=LT*RT;
            else temp=LT*RF+LF*RT+LF*RF;
        }
        else if(exp[k]=='|'){
            if(isTrue) temp=LT*RT+LT*RF+LF*RT;
            else temp=LF*RF;
        }
        else if(exp[k]=='^'){
            if(isTrue) temp=LT*RF+LF*RT;
            else temp=LT*RT+LF*RF;
        }

        ways+=temp;
    }
    return dp[i][j][isTrue]=ways;
}
int evaluateExp(string & exp) {
    int n=exp.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (n, vector<int> (2,0)));
    return f(0,n-1,1,exp,dp);
}

//Tabulation
int evaluateExp(string & exp) {
    int n=exp.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (n, vector<int> (2,0)));
    int mod=1000000007;

    for(int i=0;i<n;i++){
        if(exp[i]=='T'){
            dp[i][i][1]=1;
            dp[i][i][0]=0;
        }
        else{
            dp[i][i][1]=0;
            dp[i][i][0]=1;
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=n-1;j++){
            for(int isTrue=0;isTrue<=1;isTrue++){
                if(i>=j) continue;
                int ways=0;
                for(int k=i+1;k<=j-1;k=k+2){
                    int LT=dp[i][k-1][1];
                    int RT=dp[k+1][j][1];
                    int LF=dp[i][k-1][0];
                    int RF=dp[k+1][j][0];

                    int temp=0;
                    if(exp[k]=='&'){
                        if(isTrue) temp=LT*RT;
                        else temp=LT*RF+LF*RT+LF*RF;
                    }
                    else if(exp[k]=='|'){
                        if(isTrue) temp=LT*RT+LT*RF+LF*RT;
                        else temp=LF*RF;
                    }
                    else if(exp[k]=='^'){
                        if(isTrue) temp=LT*RF+LF*RT;
                        else temp=LT*RT+LF*RF;
                    }

                    ways+=temp;
                }
                dp[i][j][isTrue]=ways%mod;
            }
        }
    }

    return dp[0][n-1][1]%mod;
}

//Space Optimization
