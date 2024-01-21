#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void inplace_merge(int arr[], int l, int m, int r){
    int b = m+1;
    if(arr[m]<=arr[b]){
        return;
    }
    while(l<=m && b<=r){
        if(arr[l]<=arr[b]){
            l++;
        }else{
            int val = arr[b];
            int i = b;
            while(i!=l){
                arr[i]= arr[i-1];
                i--;
            }
            arr[l]= val;
            l++;
            m++;
            b++;
        }
    }
}

void inplace_mergesort(int arr[], int l, int r){
    int a=0;
    int n= r-l+1;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i]){
            a = i;
        }
    }
    inplace_merge(arr, l,a,r );
}
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error finding the file"<<endl;
        return 1;
    }
    int n;
    inputFile>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        inputFile>>arr[i];
    }
    inputFile.close();
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error finding the file"<<endl;
        return 1;
    }
    inplace_mergesort(arr,0,n-1);
    outputFile<<"Sorted array is"<<endl;
    for(int i=0;i<n;i++){
        outputFile<<arr[i]<<" ";
    }
    outputFile<<endl;
    outputFile.close();
    return 0;
}