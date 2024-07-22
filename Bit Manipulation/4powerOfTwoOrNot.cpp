#include<iostream>
using namespace std;

//
bool isPowerOfTwo(int n) {
    if(n>0 && (n & (n-1))==0) return true;
    return false;
}

//there should be only one bit in no.