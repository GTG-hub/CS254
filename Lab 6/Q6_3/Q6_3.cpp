//Garima Upadhyay
//220001029
//Find strongly connected components from a directed graph.
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAX_N = 1e5;
struct Node {
  vector < int > adj;
  vector < int > rev_adj;
};

Node g[MAX_N];

stack < int > S;
bool visited[MAX_N];

int component[MAX_N];
vector <int> components[MAX_N];
int numComponents;

void dfs_1(int x) {
    visited[x] = true;
    for (int i = 0; i < g[x].adj.size(); i++) {
        if (!visited[g[x].adj[i]]) dfs_1(g[x].adj[i]);
    }
    S.push(x);
}

void dfs_2(int x) {
    cout<<" "<<x<<" ";
    component[x] = numComponents;
    components[numComponents].push_back(x);
    visited[x] = true;
    for (int i = 0; i < g[x].rev_adj.size(); i++) {
        if (!visited[g[x].rev_adj[i]]) dfs_2(g[x].rev_adj[i]);
    }
}

void Kosaraju() {
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs_1(i);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    while (!S.empty()) {
        int v = S.top();
        S.pop();
        if (!visited[v]) {
            cout<<"Component "<<numComponents<<": ";
            dfs_2(v);
            numComponents++;
            cout<<endl;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        g[a].adj.push_back(b);
        g[b].rev_adj.push_back(a);
    }

    Kosaraju();
    cout<<"Total no. of components="<<numComponents<<endl;

    return 0;
}