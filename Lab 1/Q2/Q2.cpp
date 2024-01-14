#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int knapSackRecursive(int W, int wt[], int v[], int n, int** dp){
    if(n<0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(wt[n]>W){
        dp[n][W] = knapSackRecursive(W, wt, v, n-1, dp);
        return dp[n][W];
    }else{
        dp[n][W] = max(v[n] + knapSackRecursive(W- wt[n], wt, v, n-1, dp), knapSackRecursive(W, wt, v, n-1, dp));
        return dp[n][W];
    }
}
int knapsack(int W, int weights[],int values[], int n){
    int** dp;
    dp = new int* [n];
    for(int i=0;i<n;i++){
        dp[i] = new int[W+1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<W+1;j++){
            dp[i][j]=-1;
        }
    }
    return knapSackRecursive(W, weights, values, n-1, dp);
}
int main(){
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()){
        cerr<<"Error finding the file"<<endl;
        return 1;
    }
    int W, n;
    int weights[n];
    int values[n];
    inputFile>>W>>n;
    for(int i=0;i<n;i++){
        inputFile>>weights[i];
    }
    for(int i=0;i<n;i++){
        inputFile>>values[i];
    }
    inputFile.close();

    int ans = knapsack(W , weights, values, n);
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error finding the file"<<endl;
        return 1;
    }
    outputFile << ans <<endl;
    outputFile.close();
    
    return 0;
}