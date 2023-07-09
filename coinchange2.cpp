#include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<long>curr(value+1,0);
    vector<long>prev(value+1,0);
    for(int i=0;i<=value;i++){
        prev[i]=i%denominations[0]==0;
    }
    for(int i=1;i<n;i++){
        for(int val=0;val<=value;val++){
            long nottake=prev[val];
            long take=0;
            if(val>=denominations[i]){
                take=curr[val-denominations[i]];
            }
            curr[val]=take+nottake;
        }
        prev=curr;
    }
    return prev[value];
}