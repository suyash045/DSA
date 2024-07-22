#include<bits/stdc++.h>
using namespace std;

//
bool isPrime(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(n/i!=i) cnt++;
        }
        if(cnt>2) break;
    }
    if(cnt==2) return true;
    return false;
}
vector<int>AllPrimeFactors(int N) {
    vector<int> ans;
    for(int i=2;i<=N;i++){
        if(N%i==0 && isPrime(i)){
            ans.push_back(i);
        }
    }
    return ans;
}

//Better approach
vector<int>AllPrimeFactors(int N) {
    vector<int> ans;
    for(int i=2;i<=N;i++){
        if(N%i==0){
            ans.push_back(i);
            while(N%i==0){
                N=N/i;
            }
        }
    }
    return ans;
}

//
vector<int>AllPrimeFactors(int N) {
    vector<int> ans;
    for(int i=2;i*i<=N;i++){
        if(N%i==0){
            ans.push_back(i);
            while(N%i==0){
                N=N/i;
            }
        }
    }
    if(N!=1) ans.push_back(N);
    return ans;
}
//TC is O(sqrt(n) * logn)