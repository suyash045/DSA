#include<bits/stdc++.h>
using namespace std;

//We can assume array as an linked list. Next pointer index is element at current index.
//Cycle will form. We have to get starting point of cycle.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};