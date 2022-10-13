/******************************************************************************

Cycle Detection in Undirected Graph using BFS

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int s, int v, vector<int> adj[], vector<int> &visited){
    queue<pair<int,int>>q;
    visited[s] = true;
    q.push({s,-1});
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto i : adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push({i,node});
            }
            else if(par != i)
                return true;
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]){
    vector<int> vis(v+1,0);
    for(int i=1; i<=v; i++){
        if(!vis[i]){
            if(checkForCycle(i,v,adj,vis))
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
