//Sieve of Eratosthenes algo
//finds prime numbers upto n
#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<bool> primes(n,1);

    for(int i=2;i*i<n;i++){
        if(!primes[i]) continue;
        for(int j=i*i;j<n;j+=i){
            primes[j]=0;
        }
    }

    int cnt=0;
    for(int i=2;i<n;i++){
        if(primes[i]==1) cnt++;
    }
    return cnt;
}
//TC is O(n)+O(nlog(logn))+O(n)
//SC is O(n)