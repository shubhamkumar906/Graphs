/******************************************************************************

Graph Representation - Adjacency List 
(for weighted graph use vector<pair<int,int>> adj[n+1])

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;                                    // n->no of nodes, m->no of edges
    cin>>n>>m;
    vector<int> adj[n+1];
    
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        int l = adj[i].size();
        cout<<i<<" ";
        for(int j=0; j<l; j++){
            cout<<adj[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
