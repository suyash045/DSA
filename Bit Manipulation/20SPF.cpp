//SPF(smallest prime factor)
#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<bool> spf(n+1);
    for(int i=0;i<n;i++) spf[i]=i;

    for(int i=2;i*i<n;i++){
        if(spf[i]!=i) continue;
        for(int j=i*i;j<n;j+=i){
            if(spf[j]==j) spf[j]=i;
        }
    }

    return spf[n];
}

//For querry problem
//querry has n we have to find prime factors of n. Here we can use SPF vector.
//Pseudo code:
//for(2 -> queries.size()){
//  n=queries[i];
//  while(n!=1){
//      print(spf[n]);
//      n=n/spf[n];
//  }
//}