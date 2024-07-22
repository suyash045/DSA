//Till now we get LIS with TC O(n^2) and SC O(n)
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> temp;
        temp.push_back(a[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(a[i]>temp.back()){
                temp.push_back(a[i]);
                len++;
            }
            else{
                int ind=lower_bound(temp.begin(), temp.end(), a[i])-temp.begin();
                temp[ind]=a[i];
            }
        }
        return len;
    }
};
//TC is O(n*logn)
//SC is O(n)

//Ex. {1,7,8,4,5,6,-1,9}
//temp : {1} -> {1,7} -> {1,7,8} -> {1,4,8} -> {1,4,5} -> {1,4,5,6} -> {-1,4,5,6} -> {-1,4,5,6,9}