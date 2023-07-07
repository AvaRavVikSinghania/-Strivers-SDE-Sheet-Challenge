#include<bits/stdc++.h>
using namespace std;
vector<int>onlineStack(int arr[],int n){
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(i);
            ans.push_back(1);
            continue;;
        }
        if(arr[st.top()]>arr[i]){
            st.push(i);
            ans.push_back(1);
        }
        else{
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
               ans.push_back(i+1);
            }else{
                ans.push_back(i-st.top());
            }
            st.push(i);
        }
    }
    return ans;
}
int main(){

}