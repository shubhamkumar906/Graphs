/******************************************************************************

Graph Traversal - BFS

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraphs(int v, vector<int> adj[]){
    vector<int> bfs;
    vector<int> vis(v+1,0);
    
    for(int i=1; i<=v; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto i : adj[node]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }
        }
    }
    return bfs;
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
    //     int l = adj[i].size();
    //     cout<<i<<" ";
    //     for(int j=0; j<l; j++){
    //         cout<<adj[i][j]<<" ";
    //     }cout<<endl;
    // }
    vector<int> bfs = bfsOfGraphs(n,adj);
    for(int i=0;i<bfs.size();i++)
        cout<<bfs[i]<<" ";
    return 0;
}
