#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    vector<int>ans;
    map<int,int>mp;
    int first=0;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
        if(i>=k-1){
            ans.push_back(mp.size());
            mp[arr[first]]--;
            if(mp[arr[first]]==0){
                mp.erase(arr[first]);
            }
            first++;
        }
    }
    return ans;
	
}
