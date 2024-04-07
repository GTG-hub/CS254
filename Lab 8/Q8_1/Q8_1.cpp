//Garima Upadhyay
//220001029
// Given an undirected weighted graph, a maximum spanning tree is a spanning tree having
// maximum weight. Devise algorithm to generate maximum spanning tree using union-find.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(vector<int> a,vector<int> b){
	if(a[0]>=b[0]){
		return true;
	}
	return false;
}

class DSU { 
	int* parent; 
	int* rank; 

public: 
	DSU(int n){ 
		parent = new int[n]; 
		rank = new int[n]; 
		for (int i = 0; i < n; i++) { 
			parent[i] = -1; 
			rank[i] = 1; 
		} 
	} 

	// Find function 
	int find(int i){ 
		if (parent[i] == -1) 
			return i; 

		return parent[i] = find(parent[i]); 
	} 

	// Union function 
	void unite(int x, int y){ 
		int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2){
            if(rank[s1]>rank[s2]){
                parent[s2] = s1;
            }else{
                parent[s1] = s2;
            }
            rank[s1]+= rank[s2];
            rank[s2] = rank[s1];
        }
	} 
}; 

class Graph { 
	vector<vector<int>> edgelist; 
	int V; 
public: 
	Graph(int V) { 
        this->V = V; 
    } 
	void addEdge(int x, int y, int w) 
	{ 
        vector<int> v;
        v.push_back(w);
        v.push_back(x);
        v.push_back(y);
		edgelist.push_back(v); 
	} 

	void kruskals_mst() 
	{ 
		sort(edgelist.begin(), edgelist.end(),cmp); 
		DSU s(V); 
		int ans = 0; 
		for (auto edge : edgelist) { 
			int w = edge[0]; 
			int x = edge[1]; 
			int y = edge[2]; 
			if (s.find(x) != s.find(y)) { 
				s.unite(x, y); 
				ans += w; 
			} 
		} 
		cout << "The cost of maximum Spanning Tree is" << ans << endl; 
	} 
}; 

int main() { 
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int V,E;
    cin >> V >> E;
    Graph g(V);
    for(int i=0;i<E;i++){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        g.addEdge(v1,v2,w);
    }
    g.kruskals_mst();
}
