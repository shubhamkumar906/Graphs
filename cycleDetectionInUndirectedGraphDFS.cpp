/******************************************************************************

Cycle Detection in Undirected Graph using DFS

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i]){
            if(checkForCycle(i,parent,vis,adj))return true;
            else if(i != parent)return true;
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]){
    vector<int> vis(v+1,0);
    for(int i=1; i<=v; i++){
        if(!vis[i]){
            if(checkForCycle(i,-1,vis,adj))
                return true;
        }
    }
    return false;
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
    
    cout<<isCycle(n,adj);
    return 0;
}
