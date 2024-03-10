//Garima Upadhyay
//220001029
// Given a directed acyclic graph G with N vertices and M edges. The task is
// to find the length of the longest path in Graph.
#include <bits/stdc++.h>
using namespace std;
vector<int> order;
void topo(int src,vector<int> &vis,vector<vector<pair<int,int> > > g){
    vis[src] = 1;
    for(auto x:g[src]){
        if(!vis[x.first])
            topo(x.first,vis,g);
    }
    order.push_back(src);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    int src;
    cin>>src;
    vector<vector<pair<int,int> > > g(n);
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
 
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topo(i,vis,g);                    
        }                                  
    }
    vector<int> dist(n);
    for(int i=0;i<n;i++) dist[i] = INT_MIN;
    dist[src] = 0;
    for(int i=n-1;i>=0;i--){
        if(dist[order[i]]!=INT_MIN){
            for(auto x:g[order[i]]){
                int v = dist[x.first];
                int w = x.second;
                int u = dist[order[i]];
                if(u + w > v)
                    dist[x.first] = u + w;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i!=src and dist[i]!=INT_MIN){
            cout<<src<<" -> "<<i<<" = "<<dist[i]<<endl;
        }
    }
 
    return 0;
}
