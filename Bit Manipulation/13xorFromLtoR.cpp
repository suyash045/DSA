#include<bits/stdc++.h>
using namespace std;

//a store xor of elements form 1 to l
//b store xor of elements form 1 to r
int findXOR(int l, int r) {
    int a,b;
    if(l%4==1) a=1;
    else if(l%4==2) a=l+1;
    else if(l%4==3) a=0;
    else if(l%4==0) a=l;
    
    if(r%4==1) b=1;
    else if(r%4==2) b=r+1;
    else if(r%4==3) b=0;
    else if(r%4==0) b=r;
    
    return a^b^l;
}