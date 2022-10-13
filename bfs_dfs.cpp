/******************************************************************************

bfs and dfs Traversals

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int n, vector<int> adj[]){
    
    vector<int> store_bfs;
    vector<int> vis(n+1,0);
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                store_bfs.push_back(node);
                
                for(auto it : adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
            
        }
    }
    return store_bfs;
}

void dfs(int node, vector<int> &vis, vector<int> &store_dfs, vector<int> adj[]){
    store_dfs.push_back(node);
    vis[node] = 1;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,store_dfs,adj);
        }
    }
}

vector<int> dfsOfGraph(int n, vector<int> adj[]){
    vector<int> store_dfs;
    vector<int> vis(n+1,0);
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,vis,store_dfs,adj);
        }
    }
    return store_dfs;
}

int main()
{
    // int n,m;
    // cin>>n>>m;
    // vector<int> adj[n+1];
    
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
        
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    
    vector<int> adj[8];
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(7);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(3);
    adj[5].push_back(7);
    adj[6].push_back(4);
    adj[7].push_back(2);
    adj[7].push_back(5);
    
    vector<int> bfs = bfsOfGraph(7,adj);
    for(int i=0;i<bfs.size();i++){
        cout<<bfs[i]<<" ";
    }cout<<endl;
    
    vector<int> dfs = dfsOfGraph(7,adj);
    for(int i=0;i<dfs.size();i++){
        cout<<dfs[i]<<" ";
    }cout<<endl;

    return 0;
}
