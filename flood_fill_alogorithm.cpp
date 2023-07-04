#include<bits/stdc++.h>
bool isPossible(int x,int y,int n,int m){
    return x>=0 && x<n && y>=0 && y<m;
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int n=image.size();
    int m=image[0].size();
    int prevcolor=image[x][y];
    image[x][y]=newColor;
    if(prevcolor==newColor) return image;
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int new_x=dx[i]+row;
            int new_y=dy[i]+col;
            if(isPossible(new_x,new_y,n,m) && image[new_x][new_y]==prevcolor){
                q.push({new_x,new_y});
                image[new_x][new_y]=newColor;
            }
        }
    }
    return image;
}