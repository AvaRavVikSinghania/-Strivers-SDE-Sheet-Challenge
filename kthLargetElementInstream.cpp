#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int>pq;
    int K;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       for(int i=0;i<arr.size();i++){
           pq.push(-1*arr[i]);
           if(pq.size()>k){
               pq.pop();
           }
       }
       K=k;
    }

    void add(int num) {
        // Write your code here.
        pq.push(-1*num);
        if(pq.size()>K){
            pq.pop();
        }
    }

    int getKthLargest() {
       // Write your code here.
       if(pq.size()<K) return -1;
        return -1*pq.top();
    }

};