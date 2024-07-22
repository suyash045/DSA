#include<bits/stdc++.h>
using namespace std;

vector<int> findPrimeFactors(int N) {
    vector<bool> primes(N+1,1);
    vector<int> ans;
    for(int i=2;i*i<=N;i++){
        if(!primes[i]) continue;
        while(N%i==0){
            ans.push_back(i);
            N=N/i;
        }
        for(int j=i*i;j<=N;j+=i){
            primes[j]=0;
        }
    }
    if(N!=1) ans.push_back(N);
    
    return ans;
}