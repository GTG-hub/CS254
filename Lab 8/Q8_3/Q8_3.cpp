//Garima Upadhyay
//220001029
// Find the second best MST of a given graph, which is a spanning tree with the second
// minimum weight sum of all edges, out of all spanning trees of graph G

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU{
    int* parent_mst;
    int* rank;
    int V;
    public:
    vector<int> parent_sec_mst;
    vector<int> present;
    int edgecount;
    DSU(int n){
        this->V = n;
        parent_mst = new int[n];
        parent_sec_mst = vector<int>(n,-1);
        rank = new int[n];
        for(int i=0;i<n;i++){
            parent_mst[i] = -1;
            rank[i] = 1;
        }
    }

    int find_mst(int i){
        if(parent_mst[i]==-1){
            return i;
        }
        return find_mst(parent_mst[i]);
    }

    int find_sec_mst(int i){
        if(parent_sec_mst[i]==-1){
            return i;
        }
        return find_sec_mst(parent_sec_mst[i]);
    }

    int uni1(int i,int sum,vector<vector<int> >& graph){
        int s1 = find_mst(graph[i][1]);
        int s2 = find_mst(graph[i][2]);

        if(s1 != s2){
            parent_mst[s1] = s2;
            present.push_back(i);
            sum+=graph[i][0];
        }
        return sum;
    }

    int uni2(int i,int sum,vector<vector<int> >& graph){
        int s1 = find_sec_mst(graph[i][1]);
        int s2 = find_sec_mst(graph[i][2]);
        if(s1 != s2){
            parent_sec_mst[s1] = s2;
            sum+=graph[i][0];
            edgecount++;
        }
        return sum;
    }
    
};

void Krushkal_mst(vector<vector<int> >& graph,int E,int V){
    int sum = 0;
    sort(graph.begin(),graph.end());
    DSU dsu(V);
    for (int i = 0; i < E; i++) {
        sum = dsu.uni1(i, sum, graph);
    }
    cout << "MST: " << sum << endl;
    int sec_best_mst = INT_MAX;
    sum = 0;
    for(int j = 0;j<dsu.present.size();j++){
        dsu.parent_sec_mst = vector<int>(V,-1);
        dsu.edgecount = 0;
        for(int i=0;i<E;i++){
            if(i== dsu.present[j]){
                continue;
            }
            sum = dsu.uni2(i,sum, graph);
        }
        if (dsu.edgecount != V - 1) {
            sum = 0;
            continue;
        }
        if (sec_best_mst > sum)
            sec_best_mst = sum;
        sum = 0;
    }
    cout << "The cost of second best minimum spanning tree is: " << sec_best_mst << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int V,E;
    cin >> V >> E;
    vector<vector<int> > graph(E,vector<int>(3));
    for(int i=0;i<E;i++){
        int s,d,w;
        cin >> s >> d >> w;
        graph[i][0] = w;
        graph[i][1] = s;
        graph[i][2] = d;
    }
    Krushkal_mst(graph,E,V);
}