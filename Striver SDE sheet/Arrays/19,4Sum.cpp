#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        if((long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l]==(long long)target){
                            vector<int> temp={nums[i],nums[j],nums[k],nums  [l]};
                            sort(temp.begin(),temp.end());
                            ans.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans1(ans.begin(),ans.end());
        return ans1;
    }
};

//
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long> present;
                for(int k=j+1;k<n;k++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth=target-sum;
                    if(present.find(fourth)!=present.end()){
                        vector<int> temp={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                    present.insert(nums[k]);
                    
                }
            }
        }

        vector<vector<int>> ans1(ans.begin(),ans.end());
        return ans1;
    }
};

//
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;

                while(k<l){
                    long long sum=nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==(long long)target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }

        return ans;
    }
};