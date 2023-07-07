 #include<bits/stdc++.h>
 using namespace std;
 int productsum(vector<int>&arr){
    int prefix=1,suffix=1;
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++){
       if(prefix==0) prefix=1;
       if(suffix==0) suffix=1;
       prefix=prefix*arr[i];
       suffix=suffix*arr[n-i-1];
       ans=max(ans,max(suffix,prefix));
    }
    return ans;
 }
 int main(){

 }