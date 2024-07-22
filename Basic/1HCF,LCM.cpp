#include<bits/stdc++.h>
using namespace std;

//HCF of 12 and 16
// 16%12,12 -> 4,12
// 12%4,4 -> 0,4
// Do this till first no. is 0. When we get first no. 0 then ans is 2nd no. 

//LCM=12*16/HCF
class Solution {
  public:
    long long hcf(long long A,long long B){
        if(A==0) return B;
        
        return (B%A,A);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long> ans;
        long long HCF=hcf(A,B);
        
        long long LCM=(A*B)/HCF;
        
        ans.push_back(LCM);
        ans.push_back(HCF);
        return ans;
    }
};