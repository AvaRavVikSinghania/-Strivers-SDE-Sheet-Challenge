#include<bits/stdc++.h>
using namespace std;
priority_queue<int>leftTop;
priority_queue<int,vector<int>,greater<int>>rightTop;
void insert(int num){
      if(leftTop.size()==0){
		  leftTop.push(num);
		  return ;
	  }
	  if(leftTop.size()>rightTop.size()){
		  if(num<leftTop.top()){
			  leftTop.push(num);
			  rightTop.push(leftTop.top());
			  leftTop.pop();
		  }else{
			  rightTop.push(num);
		  }
	  }else{
          if(num<leftTop.top()){
			  leftTop.push(num);
		  }else{
			  rightTop.push(num);
			  leftTop.push(rightTop.top());
			  rightTop.pop();
		  }
	  }
}
int getmedian(){
	if(leftTop.size()==rightTop.size()){
		return (leftTop.top()+rightTop.top())/2;
	}
	return leftTop.top();
}
// priority_queue<int>larger;
// priority_queue<int,vector<int>,greater<int>>smaller;
// void insert(int num){
//       if(larger.size()==0){
//           larger.push(num);
//           return ;
//       }
//       if(larger.size()>smaller.size()){
//           if(num<larger.top()){
//               larger.push(num);
//               smaller.push(larger.top());
//               larger.pop();
//           }else{
//               smaller.push(num);
//           }
//       }else{
//           if(num>larger.top()){
//              smaller.push(num);
//               larger.push(smaller.top());
//               smaller.pop();
//           }else{
//               larger.push(num);
//           }
//       }
// }
// int getmedian(){
//     if(larger.size()==smaller.size()){
//         return (larger.top()+smaller.top())/2;
//     }
//     return larger.top();
// }
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here

	vector<int>ans;
	for(int i=0;i<n;i++){
		insert(arr[i]);
	    int md=getmedian();
		ans.push_back(md);
		cout<<md<<" ";
	}
	return ans;
}
int main(){
    vector<int>arr={5 ,5 ,1 ,12 ,1 ,11 ,10, 2, 12 ,6 ,6 };
    findMedian(arr,11);
    return 0;
}
