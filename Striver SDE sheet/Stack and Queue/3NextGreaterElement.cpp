#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2=nums2.size();
        unordered_map<int,int> m;
        stack<int> st;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()) st.pop();
            if(st.empty()) m[nums2[i]]=-1;
            else m[nums2[i]]=st.top();

            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            nums1[i]=m[nums1[i]];
        }
        return nums1;
    }
};