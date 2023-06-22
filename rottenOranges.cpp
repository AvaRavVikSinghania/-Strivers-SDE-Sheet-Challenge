#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,pair<int,int>>>pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
              pq.push({0, {i, j}});
              vis[i][j] = 1;
            }
        }
    }
    int ans=0;
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    while(!pq.empty()){
        int size=pq.size();
        for(int i=0;i<size;i++){
            int x=pq.front().second.first;
            int y=pq.front().second.second;
            int time=pq.front().first;
            ans=max(ans,time);
            pq.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                  pq.push({time+1, {nx, ny}});
                  vis[nx][ny] = 1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]==1) return -1;
        }
    }
    return ans;
}