bool dfs(int i,int parent, vector<int>adj[],vector<int>vis){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            if(dfs(it,i,adj,vis)==true) return true;
        }
        else if(it!=parent) return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>vis(n+1,0);
    for(int i=1;i<n;i++){
        if(!vis[i]){
            if(dfs(i,-1,adj,vis)==true) return "Yes";
        }
    }
    return "No";
}
