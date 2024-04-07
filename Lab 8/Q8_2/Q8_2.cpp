//Garima Upadhyay
//220001029
// Given a graph with n nodes and m edges where each edge has a color (either black or
// green) and a cost associated with it. Find the minimum spanning tree of the graph such
// that every path in the tree is made up of alternating colored edges.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long minCost(int n, int m, int mask, int prev, int col,vector<vector<vector<int> > >& graph,vector<vector<vector<int> > >& dp){
    if (mask == ((1 << n) - 1)) {
        return 0;
    }
    if (dp[mask][prev][col == 1] != 0) {
        return dp[mask][prev][col == 1];
    }
 
    long long ans = 1e9;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (graph[prev][i][j] && !(mask & (1 << i)) 
                && (j != col)) {
                long long z = graph[prev][i][j] + 
                              minCost(n,m,mask|(1<<i),i,j,graph,dp);
                ans = min(z, ans);
            }
        }
    }
    return dp[mask][prev][col==1] = ans;
}

int graphCost(vector<pair<pair<int,int> ,pair<int,char> > >& g,int m,int n){
    vector<vector<vector<int> > > gr(n,vector<vector<int> >(n,vector<int>(2)));
    for(int i=0;i<m;i++){
        gr[g[i].first.first][g[i].first.second][g[i].second.second == 'G'] = g[i].second.first;
    }
    vector<vector<vector<int> > > dp((1<<n),vector<vector<int> >(n,vector<int> (2)));
    long long ans = 1e9;
 
    for (int i = 0; i < n; i++) {
        ans = min(ans, minCost(n, m, 1 << i, i, 2,gr,dp));
    }
    if (ans != 1e9) {
        return ans;
    }
    else {
        return -1;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin >> n >> m;
    vector<pair<pair<int,int>,pair<int,char>>>g ;
    for(int i=0;i<m;i++){
        int v1,v2,w;
        char col;
        cin >> v1 >> v2 >> w >> col;
        g.push_back(make_pair(make_pair(v1,v2),make_pair(w,col)));
    }
    cout << graphCost(g,m,n) << endl;
    
}