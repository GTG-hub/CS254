//Garima Upadhyay
//220001029
// A Clique is a subgraph of a graph such that all vertices in the subgraph are completely con-
// nected. Given a Graph, find if it can be divided into two Cliques.
#include <bits/stdc++.h>
using namespace std;
//Graph can be divided into two cliques if its complement graph is bipartite
//Time Complexity:O(N^2) Space Complexity:O(N^2)
bool isBipartite(vector<vector<int> >& adj_mat,vector<int>& color_mat){
    int n = adj_mat.size();
    for(int i=0;i<n;i++){
        if(color_mat[i]==-1){
            queue<int> q;
            color_mat[i] = 1;
            q.push(i);
            while(!q.empty()){
                int c = q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(adj_mat[c][j]==1 && color_mat[j]==-1){
                        color_mat[j] = 1-color_mat[c];
                        q.push(j);
                    }else if(adj_mat[c][j]==1 && color_mat[j]==color_mat[c]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
};

bool canDivideintoClique(vector<vector<int> >& adj_mat){
    int n = adj_mat.size();
    vector<int>  color_mat(n,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                adj_mat[i][j] = 0;
                continue;
            }
            adj_mat[i][j] = !adj_mat[i][j];
        }
    }
    return isBipartite(adj_mat,color_mat);
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<vector<int>> adj_mat;
    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            int k;
            cin >> k;
            row.push_back(k);
        }
        adj_mat.push_back(row);
    }
    cout << (canDivideintoClique(adj_mat)?"YES" : "NO") << endl;
    
    return 0;
}