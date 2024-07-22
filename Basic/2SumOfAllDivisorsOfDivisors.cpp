//https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
#include<bits/stdc++.h>
using namespace std;

//Ex n=6
// 1 : 1
// 2 : 1,2
// 3 : 1,3
// 4 : 1,2,4
// 5 : 1,5
// 6 : 1,2,3,6
// ans=sum of all above

//So in ans
//1 is 6 times (n/1)
//2 is 3 times (n/2)
//3 is 2 times (n/3)
//4 is 1 times (n/4)
//5 is 1 times (n/5)
//6 is 1 times (n/6)

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum=0;
        for(long long i=1;i<=N;i++){
            sum+=i*(N/i);
        }
        
        return sum;
    }
};