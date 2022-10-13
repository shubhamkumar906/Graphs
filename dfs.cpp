/******************************************************************************

Graph Traversal - DFS

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs){
    storeDfs.push_back(node);
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i])
            dfs(i,vis,adj,storeDfs);
    }
}

vector<int> dfsOfGraphs(int v, vector<int>adj[]){
    vector<int> storeDfs;
    vector<int> vis(v+1,0);
    for(int i=1; i<=v; i++){
        if(!vis[i]){
            dfs(i,vis,adj,storeDfs);
        }
    }
    return storeDfs;
}
    

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(int i=1; i<=n; i++){
    //     int m = adj[i].size();
    //     cout<<i<<" ";
    //     for(int j=0; j<m; j++){
    //         cout<<adj[i][j]<<" ";
    //     }cout<<endl;
    // }
    
    
    vector<int> dfs = dfsOfGraphs(n,adj);
    for(int i=0;i<dfs.size();i++)
        cout<<dfs[i]<<" ";
    return 0;
}
