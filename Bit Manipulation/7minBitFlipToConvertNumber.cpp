#include<iostream>
using namespace std;

int minBitFlips(int start, int goal) {
    int cnt=0;
    for(int i=0;i<32;i++){
        if(((start & (1<<i))!=0)==((goal & (1<<i))!=0)) continue;
        else cnt++;
    }
    return cnt;
}

