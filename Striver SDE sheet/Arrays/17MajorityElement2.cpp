//Find element which is more than n/3 times occur in array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }

        vector<int> ans;
        for(auto i:count){
            if(i.second>n/3) ans.push_back(i.first);
        }
        return ans;
    }
};

//optimal
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int cnt1=0,cnt2=0,ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1==0 && (ele2!=nums[i] || i==0)){
                ele1=nums[i];
                cnt1++;   
            }
            else if(cnt2==0 && ele1!=nums[i]){
                ele2=nums[i];
                cnt2++;   
            }
            else if(ele1==nums[i]) cnt1++;
            else if(ele2==nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) count1++;
            if(nums[i]==ele2) count2++;
        }

        if(count1>n/3) ans.push_back(ele1);
        if(count2>n/3) ans.push_back(ele2);

        return ans;
    }
};