#include<bits/stdc++.h>
using namespace std;

//
class Solution {
public:
    bool isSafe(vector<string> &board,int row,int col){
        int r=row;
        int c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }

        r=row,c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            c--;
        }

        r=row,c=col;
        while(row<board.size() && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }
    void f(int col,int n,vector<string> board,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(board,row,col)){
                board[row][col]='Q';
                f(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s="";
        for(int i=0;i<n;i++) s.push_back('.');

        for(int i=0;i<n;i++) board.push_back(s);

        vector<vector<string>> ans;
        f(0,n,board,ans);
        return ans;
    }
};

//Using hashing
class Solution {
public:
    void f(int col,int n,vector<string> board,vector<vector<string>> &ans,vector<int> leftRow,vector<int> upperDia,vector<int> lowerDia){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && upperDia[n-1+col-row]==0 && lowerDia[row+col]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                upperDia[n-1+col-row]=1;
                lowerDia[col+row]=1;

                f(col+1,n,board,ans,leftRow,upperDia,lowerDia);
                
                leftRow[row]=0;
                upperDia[n-1+col-row]=0;
                lowerDia[col+row]=0;
                board[row][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s="";
        for(int i=0;i<n;i++) s.push_back('.');

        for(int i=0;i<n;i++) board.push_back(s);

        vector<vector<string>> ans;
        vector<int> leftRow(n,0),upperDia(2*n-1,0),lowerDia(2*n-1,0);
        f(0,n,board,ans,leftRow,upperDia,lowerDia);
        return ans;
    }
};