#include<bits/stdc++.h>
using namespace std;
class disjpointset{
     vector<int>rank,parent,size;
     public:
     disjpointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
     }
     int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
     }
     void unionByrank(int u ,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return ;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
     }
     void unionBysize(int u ,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        
     }
};
int main(){
         disjpointset ds(7);
         ds.unionByrank(1,2);
         ds.unionByrank(2,3);
         ds.unionByrank(4,5);
         ds.unionByrank(6,7);
         ds.unionByrank(5,6);
         if(ds.findUpar(3)==ds.findUpar(7)){
            cout<<"same"<<endl;
         }
         else cout<<"no"<<endl;
         ds.unionByrank(3,7);
         if(ds.findUpar(3)==ds.findUpar(7)){
            cout<<"same"<<endl;
         }
         else cout<<"no"<<endl;
         return 0;
}