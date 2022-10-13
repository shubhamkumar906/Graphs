/******************************************************************************

Graph Representation - Adjacency Matrix

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];
    memset(adj,0,sizeof(adj));
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         if(adj[i][j] != 1)
    //             adj[i][j] = 0;
    //     }
    // }
    // otherwise initially intialize with memset(t,0,sizeof(adj));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
