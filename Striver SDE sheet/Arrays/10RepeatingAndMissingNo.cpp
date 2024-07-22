#include<bits/stdc++.h>
using namespace std;

//Ex. {{1,3}{2,2}}
//here n=4
//Sn=n(n+1)/2=10, S2n=n(n+1)(2n+1)/6
//real sum=8, squareSum=18
//x-y=sum-Sn
//x^2-y^2=squareSum-S2n
//x+y=(x^2-y^2)/(x-y)
//hence we can get x and y
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        long long N=n*n;
        long long Sn=N*(N+1)/2;
        long long S2n=N*(N+1)*(2*N+1)/6;

        long long sum=0;
        long long squareSum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                squareSum+=(long long)grid[i][j]*(long long)grid[i][j];
            }
        }

        long long xmiy=sum-Sn;
        long long xply=squareSum-S2n;
        xply=xply/xmiy;

        long long x=(xply+xmiy)/2;
        long long y=xply-x;

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==x) count++;
            }
        }

        if(count==2) return {(int)x,(int)y};
        else return {(int)y,(int)x};
    }
};