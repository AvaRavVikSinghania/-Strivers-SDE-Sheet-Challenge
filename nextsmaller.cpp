#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st;
    st.push(arr[n-1]);
    vector<int>ans;
    ans.push_back(-1);
    for(int i=n-2;i>=0;i--){
        if(st.top()<arr[i]){
            ans.push_back(st.top());
            st.push(arr[i]);
        }else{
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}