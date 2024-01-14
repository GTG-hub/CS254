#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMaxSum(int arr[], int n){
    int max =INT_MIN;
    int sec_max = INT_MIN;
    if(arr[0]>arr[1]){
        max = arr[0];
        sec_max = arr[1];
    }else{
        max = arr[1];
        sec_max = arr[0];
    }
    for(int i=2;i<n;i++){
        if(arr[i]>max ){
            sec_max = max;
            max = arr[i];
        }else if(arr[i]>sec_max){
            sec_max = arr[i];
        }
    }
    return (max + sec_max);
}


int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the file"<<endl;
        return 1;
    }
    int n;
    inputFile>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        inputFile>>arr[i];
    }
    inputFile.close();

    int sum = findMaxSum(arr, n);

    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the file"<<endl;
        return 1;
    }

    outputFile << sum << endl;
    outputFile.close();
    return 0;
}