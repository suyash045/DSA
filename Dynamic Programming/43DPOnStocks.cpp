//Best time to buy and sell stock (maximum profit by only one transaction)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int maxprofit=0;
        for(int i=1;i<n;i++){
            int profit=prices[i]-mini;
            maxprofit=max(profit,maxprofit);
            mini=min(mini,prices[i]);
        }
        return maxprofit;
    }
};