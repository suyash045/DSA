//https://www.naukri.com/code360/problems/subarrays-with-xor-k_6826258?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
using namespace std;

//Ex. {4,2,2,6,4}
//x=4^2 
//b=2^6^4      ,b is target  
//then x^b=y
//(x^b)^b=y^b
//x=y^b
#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n=a.size();
    int cnt=0;
    int xr=0;
    map<int,int> m;
    m[0]=1;
    for(int i=0;i<n;i++){
        xr=xr^a[i];
        cnt+=m[xr^b];
        m[xr]+=1;
    }
    return cnt;
}
