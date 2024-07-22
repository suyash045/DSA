//Count total bits of numbers 1,2,3,...,n
#include<iostream>
using namespace std;

//Brute force
int countSetBits(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x=1;
        while(x<=i){
            if((x&i)!=0) cnt++;
            x=x<<1;
        }
    }
    return cnt;
}

//Using stl
int countSetBits(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=__builtin_popcount(i);
    }
    return cnt;
}

//Remove set bits from rightmost
int countSetBits(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        int temp=i;
        while(temp!=0){
            temp=temp & (temp-1);
            cnt++;
        }
    }
    return cnt;
}

//Optimal
//Ex. n=14
//   DCBA
//0  0000
//1  0001
//2  0010
//3  0011
//4  0100
//5  0101
//6  0110
//7  0111
//8  1000
//9  1001
//10 1010
//11 1011
//12 1100
//13 1101
//14 1110
// Every alternate bits in A are set
// Every 2 alternate bits in B are set
// Evert 4 alternate bits in C are set
// ........
// This will keep on repeating for every power of 2 .
int countSetBits(int n){
    n++;
    int cnt=0;
    for(int i=2;i/2<n;i=i*2){
        int quotient=n/i;
        cnt+=quotient*i/2;
        
        int remainder=n%i;
        
        if(remainder>i/2) cnt+=remainder-i/2;
    }
    return cnt;
}