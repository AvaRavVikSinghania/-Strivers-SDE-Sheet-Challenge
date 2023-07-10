#include <bits/stdc++.h> 
bool check(int i,int sum,vector<int>&arr,vector<vector<int>>&dp){
    if(i==arr.size()){
        if(sum==0)  return true;
        return  false;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    int nottake=check(i+1,sum,arr,dp);
    int take=0;
    if(arr[i]<=sum){
        take=check(i+1,sum-arr[i],arr,dp);
    }
    return dp[i][sum]=take|nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // return check(0,k,arr,dp);
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    dp[n][0]=1;
    for(int i=n-1;i>=0;i--){
        for(int sum=0;sum<=k;sum++){
        int nottake=dp[i+1][sum];
        int take=0;
        if(arr[i]<=sum){
            take=dp[i+1][sum-arr[i]];
        }
        dp[i][sum]=take|nottake;
    }
}
    return dp[0][k];
}