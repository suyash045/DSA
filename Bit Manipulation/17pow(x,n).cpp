#include<bits/stdc++.h>
using namespace std;

//Ex. pow(2,10)
//    pow(4,5)
//  4*pow(4,4)
//  4*pow(16,2)
//  4*pow(256,1)
//  1024
double myPow(double x, int n) {
    double ans=1.00;
    long long nn=n;
    if(nn<0) nn=-1*nn;

    while(nn){
        if(nn%2==0){
            x=x*x;
            nn=nn/2;
        }
        else{
            ans=ans*x;
            nn=nn-1;
        }
    }

    if(n<0) ans=(double)1.0/ans;
    return ans;
}
//TC is O(logn) base 2
