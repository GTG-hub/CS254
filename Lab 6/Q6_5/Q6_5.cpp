//Garima Upadhyay
//220001029
//Find if a directed graph contain articulation nodes and bridges.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,int parent, vector<int> &desc, vector<int> & par, vector<int> & low, vector<bool> &vis, vector<int> adj[], int timer){
    desc[node] = low[node] = timer++;
    vis[node] = true;
    for(auto nbr: adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr, node, desc, par, low, vis, adj, timer);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr]> low[node]){
                return true;
            }
        }else{
            low[node] = min(low[node],desc[nbr]);
        }

    }
    return false;
}
bool findBridges(vector<int> adj[], int n){
    vector<int> desc(n,-1);
    vector<int> par(n, -1);
    vector<int> low(n,-1);
    vector<bool> vis(n, false);
    int timer=0;
    if(dfs(adj[0][0],-1, desc, par, low, vis, adj, timer)){
        return true;
    }
    return false;
}
bool dfs2(int node,int parent, vector<int> &desc, vector<int> & par, vector<int> & low, vector<bool> &vis, vector<int> adj[], int timer){
    desc[node] = low[node] = timer++;
    vis[node] = true;
    for(auto nbr: adj[node]){
        if(node == parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr, node, desc, par, low, vis, adj, timer);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr]>=desc[node] && parent==-1){
                return true;
            }
        }else{
            low[node] =  min(low[node], desc[nbr]);
        }
    }
    return false;

}
bool articulationPoint(vector<int> adj[], int n){
    vector<int> desc(n,-1);
    vector<int> par(n, -1);
    vector<int> low(n,-1);
    vector<bool> vis(n, false);
    int timer=0;
    if(dfs(adj[0][0],-1, desc, par, low, vis, adj, timer)){
        return true;
    }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(findBridges(adj, n)){
        cout<<"Bridge is there in the graph"<<endl;
    }else{
        cout<<"There is no bridge in the graph"<<endl;
    }
    if(articulationPoint(adj, n)){
        cout<<"Articulation point is there in the graph"<<endl;
    }else{
        cout<<"There is no articulation point in the graph"<<endl;
    }
}