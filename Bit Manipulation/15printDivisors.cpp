#include<bits/stdc++.h>
using namespace std;

void print_divisors(int n) {
    for(int i=1;i<=n;i++){
        if(n%i==0) cout<<i<<" ";
    }
}

//Better approach
void print_divisors(int n) {
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if(n/i!=i) cout<<n/i<<" ";
        }
    }
}