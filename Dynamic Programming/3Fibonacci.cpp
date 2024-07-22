//Fibonacci: (Tabulation Solution)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-2]+dp[i-1];
    }
    cout<<dp[n];
return 0;
}
//TC is O(n)for loop
//SC is O(n)for dp vector 
//we reduced recursion stack space 