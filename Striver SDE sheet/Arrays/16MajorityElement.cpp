//Find element which is more than n/3 times occur in array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        for(auto i:count){
            if(i.second>n/2) return i.first;
        }
        return -1;
    }
};

//Optimal
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                ele=nums[i];
                cnt++;
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ele;
    }
};