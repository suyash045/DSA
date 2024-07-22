//without using multiplication, divide, modulo operator
#include<bits/stdc++.h>
using namespace std;

//Ex. dividend=10, divisor=3
//go on adding 3 until it cross 10 
//3+3+3 hence ans is 3
int divide(int dividend, int divisor) {
    bool flag=0;
    long long divis=divisor;
    long long divid=dividend;
    if((divid<0 && divis>=0) || (divid>=0 && divis<0)) flag=1;
    if(divis<0) divis=-divis;
    if(divid<0) divid=-divid;

    long long sum=0,cnt=0;
    while(sum<=divid){
        sum=sum+divis;
        cnt++;
    }

    if(flag==1){
        cnt=-(cnt-1);
        if(cnt<INT_MIN) return INT_MIN;
        return cnt;
    }
    cnt=cnt-1;
    if(cnt>INT_MAX) return INT_MAX;
    return cnt;
}

//better approach
//Ex. dividend=22, divisor=3
// 3 * pow(2,0)=3;
// 3 * pow(2,1)=6;
// 3 * pow(2,2)=12;
// 3 * pow(2,3)=24;
// dividend=22-12=10, ans=4
//
// 3 * pow(2,0)=3;
// 3 * pow(2,1)=6;
// 3 * pow(2,2)=12;
// dividend=10-6=4, ans=4+2
//
// 3 * pow(2,0)=3;
// 3 * pow(2,1)=6;
// 3 * pow(2,2)=12;
// dividend=4-3=1, ans=4+2+1
// ans=7
int divide(int dividend, int divisor) {
    bool flag=0;
    if((dividend<0 && divisor>=0) || (dividend>=0 && divisor<0)) flag=1;
    long long divis=abs(divisor);
    long long divid=abs(dividend);

    long long ans=0;
    while(divid>=divis){
        long long i=1;
        while(divis*i<=divid){
            i=i*2;
        }
        divid-=divis*i/2;
        ans+=i/2;
    }

    if(flag==1){
        ans=-ans;
        if(ans<INT_MIN) return INT_MIN;
        return ans;
    }
    if(ans>INT_MAX) return INT_MAX;
    return ans;
}