#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=prices[0],profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            profit=max(prices[i]-cost,profit);
            cost=min(cost,prices[i]);
        }
        return profit;
    }
};