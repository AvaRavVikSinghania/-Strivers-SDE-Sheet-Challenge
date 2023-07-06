#include<bits/stdc++.h>
using namespace std;
bool isPossible(int mid,vector<int>&arr,int player){
     int p=1;
     int n=arr.size();
     int prev=arr[0];
     for(int i=1;i<n;i++){
        if(arr[i]-prev>=mid){
            p++;
            prev=arr[i];
        }
     }
     return p>=player;
}
int maxView(vector<int>&arr,int player){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int minview=1;
    int maxview=arr[n-1];
    int ans=0;
    while(minview<=maxview){
        int mid=(minview+maxview)/2;
        if(isPossible(mid,arr,player)){
            ans=mid;
            minview=mid+1;
        }else{
            maxview=mid-1;
        }
    }
    return ans;
}
int main(){

}