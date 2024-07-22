#include<bits/stdc++.h>
using namespace std;
//
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> col(m,-1);
        vector<int> row(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    col[j]=0;
                    row[i]=0;
                } 
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==0 || col[j]==0){
                    matrix[i][j]=0;
                }
            }
        }

    }
};
//TC is O(n*m)+O(n*m)
//SC is O(n)+O(m)

//more Optimal
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(j!=0) matrix[0][j]=0;
                    if(j==0) col0=0;
                    matrix[i][0]=0;
                } 
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(j!=0 && matrix[0][j]==0){ 
                    matrix[i][j]=0;
                }
                else if(j==0 && col0==0){
                    matrix[i][0]=0;
                }
                else if(matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(matrix[0][0]==0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }

        if(col0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }

    }
};
//TC is O(n*m)+O(n*m)
//SC is O(1)