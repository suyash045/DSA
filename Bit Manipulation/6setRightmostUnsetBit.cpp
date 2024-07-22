#include<iostream>
using namespace std;

//
int setBit(int n) {
    int i=1;
    while((n & i)!=0){
        i=(i<<1);
    }
    return n | i;
}
//TC is O(logn) as we are dividing by 2(<<1) after every iteration
//SC is O(1)