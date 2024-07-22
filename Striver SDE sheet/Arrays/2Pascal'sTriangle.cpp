#include<bits/stdc++.h>
using namespace std;
//arr[i][j]=(i)C(j)

//For printing pascal's triangle 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);

        for(int i=1;i<numRows;i++){
            ans[i].push_back(1);
            for(int j=1;j<i;j++){
                ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans[i].push_back(1);
        }

        return ans;
    }
};

//For printing a single row
//We can use the nCr formula. TC O(n*r)
//We can optimize it to O(n)
//Ex. n=4
//ans[1]=ans[0]*4/1
//ans[2]=ans[1]*3/2
vector<int> generate(int n) {
    vector<int> ans(n+1);
    ans[0]=1;
    ans[n]=1;

    for(int i=1;i<n;i++){
        ans[i]=ans[i-1]*(n-i+1)/i;
    }

    return ans;
}
