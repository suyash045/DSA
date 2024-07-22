#include<bits/stdc++.h>
using namespace std;

//Upper bound : smallest index such that arr[ind]>x
int upperBound(vector<int> &arr, int x, int n){
	int ans=n;
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]>x){
			ans=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	return ans;	
}
//TC is O(logn) base 2

//STL 
//for vector :
// ub=upper_bound(arr.begin(),arr.end())-arr.begin();
//for array :
// ub=upper_bound(arr,arr+n)-arr;
//