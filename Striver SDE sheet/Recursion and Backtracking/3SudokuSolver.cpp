#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int k,int row,int col,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==k) return false;
            if(board[i][col]==k) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==k) return false;
        }

        return true;
    }
    bool f(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k='1';k<='9';k++){
                        if(isValid(k,i,j,board)){
                            board[i][j]=k;
                            bool temp=f(board);

                            if(temp) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool temp=f(board);
        return;
    }
};