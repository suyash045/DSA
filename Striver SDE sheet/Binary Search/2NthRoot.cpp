#include<bits/stdc++.h>
using namespace std;

//Brute force 
//TC is O(m * logn) logn for finding nth power

//Binary search
int power(int mid,int n,int m){
  long long ans=1;
  for(int i=0;i<n;i++){
    ans=ans*mid;
    if(ans>m) return 0;
  }
  if(ans==m) return 1;
  else if(ans<m) return 2;
}
int NthRoot(int n, int m) {
  int beg=1,end=m/2;
  while(beg<=end){
    int mid=(beg+end)/2;

    int temp=power(mid,n,m);
    
    if(temp==1){
      return mid;
    }
    else if (temp==2) {
      beg = mid + 1;
    } 
    else if(temp==0){
      end = mid - 1;
    }
  }

  return -1;
}
//TC is O(logm)