//Garima Upadhyay
//220001029
//Determine the existence of loop in a directed graph
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool dfs(int i, vector<int> adj[],int vis[], int pathVis[]){
    vis[i]=1;
    pathVis[i]=1;
    for(auto it: adj[i]){
        if(!vis[it]){if(dfs(it, adj , vis, pathVis))return true;}
        else if(pathVis[i]){
            return true;
        }
    }
    pathVis[i] = 0;
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,m; // Number of vertices and number of edges
    cin>>n>>m;
    vector<int> adj[n];
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    bool aa = false;
    int vis[n] = {0};
    int pathVis[n]={0};
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, pathVis)){
                aa = true;
            }
        }
    }
    if(aa){
        cout<<"Cycle exists"<<endl;
    }else{
        cout<<"Cycle does not exist"<<endl;
    }
    return 0;
}