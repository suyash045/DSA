#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int curr=image[sr][sc];
        if(color == curr) return image;
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int l=0;l<4;l++){
                int newx=x+dx[l];
                int newy=y+dy[l];

                if(newx>=0 && newx<n && newy>=0 && newy<m){
                    if(image[newx][newy]==curr){
                        image[newx][newy]=color;
                        q.push({newx,newy});
                    }
                }
            }            
        }
        return image;
    }
};