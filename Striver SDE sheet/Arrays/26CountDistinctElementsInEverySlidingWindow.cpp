//https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
#include<bits/stdc++.h>
using namespace std;

//Brute force
class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
        for(int i=k-1;i<n;i++){
            set<int> s;
            for(int j=i-(k-1);j<=i;j++){
                s.insert(A[j]);
            }
            ans.push_back(s.size());
        }
        return ans;
    }
};

//Optimal
class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<k;i++){
            m[A[i]]++;
        }
        ans.push_back(m.size());
        for(int i=1;i<n-k+1;i++){
            m[A[i-1]]--;
            if(m[A[i-1]]==0) m.erase(A[i-1]);
            m[A[i+k-1]]++;
            ans.push_back(m.size());
        }
        return ans;
    }
};