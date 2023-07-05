#include<bits/stdc++.h>
using namespace std;
//linear ordering of vertices such that if there is an edge between u nad v then u appear before v in that ordering
//Directed and uncyclic graph
void dfs(int node,int vis[],stack<int>&st,vector<int>adj[]){
   vis[node]=1;
   for(auto it:adj[node]){
    if(!vis[it]){
        dfs(it,vis,st,adj);
    }
   }
   st.push(node);
}
vector<int>topologiclaSort(int V,vector<int>adj[]){
    int vis[V]={0};
    stack<int>st;
    for(int i=0;i<V;i++){
     if(!vis[i]){
        dfs(i,vis,st,adj);
     }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
// Time complexity will be O(N+M) for traversing the graph (dfs)+ 
//we are using a for loop for storing the result it will run no of node in graph 
// So overall time complexity will be O(N+M) approx
// Space complexity O(n)+O(n)+O(n) for visited ,stack and storing the result repectively
//Auxiliary Space O(n);
int main(){
    int n,m;
     cout<<"ENTER TOTAL NO OF NODE = "<<endl;
     cin>>n;
     cout<<"ENTER TOTAL NO OF EDGES = "<<endl;
     cin>>m;
     vector<int>adj[n];
     for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     vector<int>toposort = topologiclaSort(n,adj);
     cout<<"TOPOSORT..."<<endl;
     for(auto it:toposort){
        cout<<it<<" ";
     }
     cout<<endl;
     return 0;
}