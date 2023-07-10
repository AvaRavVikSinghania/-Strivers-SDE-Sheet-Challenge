int f(int length,vector<int>&arr,vector<int>&dp){
	if(length==0){
		return 0;
	}
	if(dp[length]!=-1) return dp[length];
	int max_ans=INT_MIN;
	for(int i=0;i<arr.size();i++){
	    int ans=0;
       if(i+1<=length) ans=arr[i]+f(length-i-1,arr,dp);
	   max_ans=max(max_ans,ans);
	}
	return dp[length]=max_ans;
}
int cutRod(vector<int> &arr, int n)
{
	// Write your code here.
	//vector<int>dp(n+1,-1);
	//return f(n,price,dp);
	vector<int>dp(n+1,0);
	for(int length=0;length<=n;length++){
		int max_ans=INT_MIN;
		for(int i=0;i<arr.size();i++){
			int ans=0;
		  if(i+1<=length) ans=arr[i]+dp[length-i-1];
		  max_ans=max(max_ans,ans);
		}
	   dp[length]=max_ans;
	}
    return dp[n];
}
