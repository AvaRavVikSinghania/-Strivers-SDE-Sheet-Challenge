#include <bits/stdc++.h> 
bool static cmp(vector<int>a,vector<int>b){
    return a[1]>=b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
      sort(jobs.begin(),jobs.end(),cmp);
      vector<int>vis(3001,0);
      int ans=0;
      int n=jobs.size();
      for(int i=0;i<n;i++){
          int profit=jobs[i][1];
          int deadline=jobs[i][0];
          for(int j=deadline;j>=1;j--){
            if(vis[j]==0){
              vis[j]=1;
              ans+=profit;
              break;
            }
          }
      }
      return ans;
}
