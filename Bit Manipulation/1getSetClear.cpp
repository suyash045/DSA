#include<iostream>
using namespace std;

void bitManipulation(int num, int i) {
    i=i-1;
    
    //Get 
    cout<<((num & (1<<i))!=0)<<" ";
    
    //Set
    cout<<(num | (1<<i))<<" "; 
    
    //Clear
    cout<<(num & ~(1<<i))<<" ";

    //Toggle
    cout<<(num ^ (1<<i))<<" ";

    //Clear rightmost set bit 
    cout<<(num & (num-1))<<" ";
    return;
}

//Logic for clearing rightmost set bit
//num   0000101011000
//num-1 0000101010111  (bits from rightmost set bit changes to 1);