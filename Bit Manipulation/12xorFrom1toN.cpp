#include<bits/stdc++.h>
using namespace std;

//n=1 1
//n=2 2
//n=3 0
//n=4 4
//
//n=5 1
//n=6 7
//n=7 0
//n=8 8
//
//n=9 1
//n=10 11
//n=11 0
//n=12 12
int f(int n){
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else if(n%4==0) return n;
}