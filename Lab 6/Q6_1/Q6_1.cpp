//Garima Upadhyay
//220001029

#include <bits/stdc++.h>
using namespace std;
vector<int> topological_sort(vector<vector<int>>& adj_list){
    int n= adj_list.size();
    vector<int> ans;
    vector<int> indegree(n);
    for(int i=0;i<n;i++){
        int m = adj_list[i].size();
        for(int j=0;j<m;j++){
            indegree[adj_list[i][j]]++;
        }
    }
    queue<int> q;
    q.push(0);
    vector<int> visited(n, 0);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(visited[a]==0 && indegree[a]==0){
            ans.push_back(a);
            visited[a]=1;
        }
        int b = adj_list[a].size();
        for(int i=0;i<b;i++){
            indegree[adj_list[a][i]]--;
            if(indegree[adj_list[a][i]]==0){
                q.push(adj_list[a][i]);
            }
        }
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<vector<int>> adj_list(n);
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            adj_list[i].push_back(x);
        }
    }
    vector<int> ans = topological_sort(adj_list);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}