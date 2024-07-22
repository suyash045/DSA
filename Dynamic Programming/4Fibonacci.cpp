//Fibonacci: (Space optimization Solution)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int prev1=1;
    int prev2=0;
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1;
return 0;
}
//TC is O(n)
//SC is O(1)
