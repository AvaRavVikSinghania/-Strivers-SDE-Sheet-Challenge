#include <bits/stdc++.h> 
int n,m;
int countSum(int i,int j,vector<vector<int>> &grid,
vector<vector<int>>&dp){
    if(i>=n|| j>=m) return 1e9;
    if(i==n-1 && j==m-1) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int sum1=0;
    int sum2=0;
    if(j+1<=m){
        sum1=grid[i][j]+countSum(i,j+1,grid,dp);
    }
    if(i+1<=n){
        sum2=grid[i][j]+countSum(i+1,j,grid,dp);
    }
    return dp[i][j]=min(sum1,sum2);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    n=grid.size();
    m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
     return countSum(0,0,grid,dp);
   // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   // dp[0][0]=grid[0][0];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//            int sum1=0;
//            int sum2=0;
//            if(j+1<=m){
//            sum1=grid[i][j]+dp[i][j+1];
//           }
//           if(i+1<=n){
//           sum2=grid[i][j]+dp[i+1][j];
//           } 
//           dp[i][j]=min(sum1,sum2);
//         }
//     }
//    return dp[n-1][m-1];
}