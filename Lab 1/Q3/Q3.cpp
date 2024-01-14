#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int nodes;
    vector<vector<int> > adj_matrix;
    Graph(int value){
        nodes=value;
        for(int i=0;i<nodes;i++){
            vector<int> v(nodes);
            adj_matrix.push_back(v);
        }
    }
    void add_wts(int i,int j,int weight){
        adj_matrix[i][j] = weight;
    }
    void add_wt_row(int i,vector<int> weights){
        adj_matrix[i] = weights;
    }
    void add_wt_mat(vector<vector<int>> weights){
        adj_matrix = weights;
    }
};


int travellingSalesman(int n,vector<vector<int> > adj_matrix, int s){
    vector<int> cities;
    for(int i=0;i<n;i++){
        if(i!=s){
            cities.push_back(i);
        }
    }
    int min_dis= INT_MAX;
    do{
        int cd = 0;
        int city = s;
        for(int i=0;i<n-1;i++){
            cd += adj_matrix[city][cities[i]];
            city = cities[i];
        }
        cd += adj_matrix[city][s];
        min_dis = min(min_dis,cd);
    }while(next_permutation(cities.begin(),cities.end()));

    return min_dis;
}

int main(){
    ofstream input("input.txt", ios::in);
    int tc;
    tc= rand()%9+1;
    input << tc << endl;
    while(tc--){                     //Code to randomly generate input distances between cities
        int num = rand()%10+1;
        input << num << endl;
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(i==j) input << 0 << " " ;
                else input << rand()%10+1 << " ";
            }
            input << endl;
        }
    }
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;                    //number of nodes present in the graph
        Graph g(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val;
                cin >> val;
                g.add_wts(i,j,val);
            }
        }
        int s = 0;
        long long min_dis = travellingSalesman(n,g.adj_matrix,s);
        cout << min_dis << endl;
    }

}