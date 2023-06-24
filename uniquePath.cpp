#include<bits/stdc++.h>
using namespace std;
int uniquePath(int n,int m,vector<vector<int>>&dp){
    if(n==1 || m==1) return 1;
    if(dp[n][m]!=-1) return dp[n][m];
    return dp[n][m]= uniquePath(n,m-1,dp)+uniquePath(n-1,m,dp);
}
int main(){
       int n,m;
       cin>>n>>m;
    //    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //    cout<<uniquePath(n,m,dp);
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       for(int i=0;i<n;i++){
         dp[i][0]=1;
       }
       for(int i=0;i<m;i++){
         dp[0][i]=1;
       }
       dp[0][0]=1;
       for(int i=1;i<n;i++){
         for(int j=1;j<m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
         }
       }
       cout<<dp[n-1][m-1];
       //space optimisation
       //why m-1 reasion bcz first  we have culculated it previous
       vector<int>dp1(n,1);
       for(int i=0;i<m-1;i++){
        for(int j=1;j<n;j++){
            dp1[j]+=dp1[j-1];
        }
       }
       cout<<dp1[n-1];
      return  0;
}