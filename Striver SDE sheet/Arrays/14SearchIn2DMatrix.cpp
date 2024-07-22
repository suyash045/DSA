#include<bits/stdc++.h>
using namespace std;

//First find out row then column
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size();
        int m =matrix[0].size();

        int row=-1;
        for(int i=0;i<n;i++){
            if(target>=matrix[i][0]) row=i;
            else break;
        }
        if(row==-1) return false;
 
        for(int j=0;j<m;j++){
            if(target==matrix[row][j]) return true;
        }

        return false;
    }
};

//Start from top right corner. If target is smaller move left. If greater move down.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size();
        int m =matrix[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(target==matrix[i][j]) return true;
            else if(matrix[i][j]>target) j--;
            else if(matrix[i][j]<target) i++;
        }
        
        return false;
    }
};

//Binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size();
        int m =matrix[0].size();

        int low=0,high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int i=mid/m;
            int j=mid-i*m;

            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target){
                low=mid+1;
            }
            else if(matrix[i][j]>target){
                high=mid-1;
            }
        }
        
        return false;
    }
};