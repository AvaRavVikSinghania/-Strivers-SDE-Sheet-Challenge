#include<bits/stdc++.h>
using namespace std;
//Problem statement is given an array and query query contains two element first element can be xor of any element  of the array when element is less or equal to second number
//query {1,3} means 1 can xor with element which is less or equal to 3 int the array;
class Node{
    public:
    Node* links[2];
    bool isContains(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
   private: Node* root;
   public:
   Trie(){
      root=new Node();
   }
   void insert(int num){
    Node* node=root;
    for(int i=31;i>=0;i--){
        int bit=(num>>i) & 1;
        if(!node->isContains(bit)){
           node->put(bit,new Node());
        }
        node=node->get(bit);
    }
   }
   int getmax(int num){
    Node* node=root;
    int maxnum=0;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(node->isContains(bit-1)){
           maxnum=maxnum|(1<<i);
           node=node->get(1-bit);
        }else{

        node=node->get(bit);
        }
    }
    return maxnum;
   }
};
vector<int>MaxXor(vector<int>arr,vector<vector<int>>query){
   sort(arr.begin(),arr.end());
   vector<pair<int,pair<int,int>>>Oq;//offline query
   int q=query.size();
   for(int i=0;i<q;i++){
       Oq.push_back({query[i][1],{query[i][0],i}});
   }
   sort(Oq.begin(),Oq.end());
   int n=arr.size();
   int index=0;
   vector<int>ans(q,0);
   Trie trie;
   for(int i=0;i<q;i++){
     int ai=Oq[i].first;
     int xi=Oq[i].second.first;
     int qind=Oq[i].second.second;
     while(index<n && arr[index]<=ai){
         trie.insert(arr[index]);
         index++;
     }
     if(index==0) ans[qind]=-1;
     else{
      ans[qind]=trie.getmax(xi);
    }

   }
   return ans;
}
int main(){

}