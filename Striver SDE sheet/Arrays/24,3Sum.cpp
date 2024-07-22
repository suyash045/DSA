#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target=-(nums[i]+nums[j]);
                if(s.find(target)!=s.end()){
                    vector<int> v={nums[i],nums[j],target};
                    sort(v.begin(),v.end());
                    ans.insert(v);
                }
            }
            s.insert(nums[i]);
        }
        vector<vector<int>> ans1(ans.begin(),ans.end());
        return ans1;
    }
};

//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]>0){                    
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++; 
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};