#include <bits/stdc++.h>
// minimumm spanning tree
// short all edges according to thier edges
using namespace std;
class disjointset{
     vector<int>rank,parent,size;
     public:
     disjointset(int n){
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
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
           int adjnode=it[0];
           int wt=it[1];
           int node=i;
           edges.push_back({wt,{node,adjnode}});
           //we can store reverse but no need
        }
    }
    sort(edges.begin(),edges.end());
    int mstwt=0;
    disjointset ds(V);
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUpar(u)!=ds.findUpar(v)){
            mstwt+=wt;
            ds.unionByrank(u,v);
        }
    }
}
int main()
{
}