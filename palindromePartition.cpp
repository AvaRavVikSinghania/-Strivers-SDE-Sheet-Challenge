#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s){
    int low=0;
    int high=s.size()-1;
    while(low<=high){
        if(s[low]!=s[high]) return false;
        low++;
        high--;
    }
    return true;

}
int f(int i,string s,vector<int>dp){
    if(i==s.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    int partition=0;
    string st="";
    for(int k=i;k<s.size();k++){
        st+=s[k];
        if(checkPalindrome(st)){
            partition=1+f(k+1,s,dp);
        }
        ans=min(ans,partition);
    }
    return dp[i]= ans;
}
int palindromePartitioning(string s) {
    // Write your code here
    // vector<int>dp(str.size(),-1);
    // return f(0,str,dp)-1;
    int n=s.size();
    vector<int>dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int ans=INT_MAX;
        int partition=0;
         string st="";
        for(int k=i;k<n;k++){
            st+=s[k];
           if (checkPalindrome(st)) {
            partition = 1 + dp[k + 1];
           }
           ans = min(ans, partition);
        }
      dp[i]= ans; 
    }
    return dp[0]-1;
}
