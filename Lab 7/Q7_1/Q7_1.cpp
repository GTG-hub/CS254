//Garima Upadhyay
//220001029
// You are given a set of items, each with a weight and a value. You need to determine which
// items to include in the collection so that the total weight is less than or equal to a given
// limit while maximizing the total cost.
// Example:
// Input: item = [i1, i2, i3, i4, i5];
// weights = [2, 5, 7, 3, 1];
// values = [10, 20, 15, 7, 5];
// Weight Limit = 10
// Output: [i1, i2, i4], with total cost 37
// (a) Design a solution using a greedy approach.
// (b) Check if your greedy algorithm can always provide the optimal solution.
// (c) If not, design an optimal solution strategy.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Greedy approach is
int knapsack_greedy(int n,int w[],int v[],int W){
    vector<pair<double,pair<int,int> > >  a;
    for(int i=0;i<n;i++){
        a.push_back(make_pair(double(v[i])/double(w[i]),make_pair(w[i],v[i])));
    }
    sort(a.begin(),a.end());
    int ans = 0;
    int wt = 0;
    for(int i=n-1;i>=0;i--){
        if(wt+a[i].second.first<=W){
            wt+=a[i].second.first;
            ans+=a[i].second.second;
        }
    }
    return ans;
}
//Dynamic programming approach is
int knapsack_dp(int n,int w[],int v[],int W){
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<W+1;i++){
        dp[0][i]= 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j>=w[i-1]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}


int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n,W;
    cin>>n>>W;
    int w[n],v[n];
    for(int i=0;i<n;i++){
        cin >> w[i];
    }
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int ans = knapsack_greedy(n,w,v,W);
    cout << "The output of greedy approach is : " << ans << endl;
    int ans_dp = knapsack_dp(n,w,v,W);
    cout << "The output of dynamic programming approach is : " << ans_dp << endl;
}