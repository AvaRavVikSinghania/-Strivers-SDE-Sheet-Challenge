#include<bits/stdc++.h>
int largestRectangle(vector < int > & height) {
   // Write your code here.
   int n=height.size();
      int leftsmaller[n],rightsmaller[n];
       stack<int>st;
       for(int i=0;i<n;i++){
           while(!st.empty() && height[st.top()]>=height[i]) st.pop();
           if(st.empty()) leftsmaller[i]=0;
           else{
               leftsmaller[i]=st.top()+1;
           }
           st.push(i);
       }
       while(!st.empty()) st.pop();
       for(int i=n-1;i>=0;i--){
          while(!st.empty() && height[st.top()]>=height[i]) st.pop();
          if(st.empty()) rightsmaller[i]=n-1;
          else{
              rightsmaller[i]=st.top()-1;
          }
          st.push(i);
       }
       int max_rectangle=0;
       for(int i=0;i<n;i++){
           max_rectangle=max(max_rectangle,(abs(rightsmaller[i]-leftsmaller[i])+1)*height[i]);
       }
       return max_rectangle;
 }