#include<bits/stdc++.h>
using namespace std;

//Brute force 
//Generate all permutations by recursion
//TC is O(n! * n)
//SC is O(n) + O(n)

//Optimal
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact=1;
        for(int i=1;i<=n;i++){
            if(i!=n) fact=fact*i;
            nums.push_back(i);
        }
        
        k=k-1;
        string ans="";
        while(true){
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0) return ans;
            k=k%fact;
            fact=fact/nums.size();
        }

        return ans;
    }
};
//TC is O(n^2)
//SC is O(n)