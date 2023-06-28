int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int ans=0;
    int cnt=0;
    int l=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) cnt++;
        while(cnt>k){
            if(arr[l]==0) cnt--;
            l++;
        }
        ans=max(ans,i-l+1);
    }
    return ans;
}
