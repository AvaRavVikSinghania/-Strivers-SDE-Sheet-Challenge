#include <bits/stdc++.h> 
int f(int i,int j,vector<int>&arr, vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT_MAX;
    int ans=0;
    for(int index=i;index<j;index++){
       ans=f(i,index,arr,dp)+arr[i-1]*arr[index]*arr[j]+f(index+1,j,arr,dp);
       mini=min(ans,mini);
    }
    return  dp[i][j]=mini;

}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(N,vector<int>(N,-1));
    return f(1,N-1,arr,dp);
}