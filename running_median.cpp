#include<bits/stdc++.h>
using namespace std;
class Solution{
      public:
      vector<int>arr;
      void insertHeap(int num){
          arr.push_back(num);
      }
      double getMedian(){
          int n=arr.size();
          sort(arr.begin(),arr.end());
          if(n%2==0){
            return (double)(arr[n/2-1]+arr[n/2])/2;
          }else{
            return arr[n/2];
          }
      }
};
class Solution2{
      public:
      priority_queue<int>smaller;
      priority_queue<int,vector<int>,greater<int>>larger;
      void insertHeap(int num){
           if(smaller.size()==0){
            smaller.push(num);
            return ;
           }
           if(smaller.size()>larger.size()){
              if(smaller.top()>num){
                smaller.push(num);
                larger.push(smaller.top());
                smaller.pop();
              }else{
                larger.push(num);
              }
           }else{
               if(smaller.top()>num){
                smaller.push(num);
               }else{
                larger.push(num);
                smaller.push(larger.top());
                larger.pop();
               }
           }
      }
      double getMedian(){
          if(smaller.size()==larger.size()){
            return (double)(smaller.top()+larger.top())/2;
          }else{
            return  (double)smaller.top();
          }
      }
};
int mian(){

}