#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// We can easiily solve this question in 0(n) time complexity by having two variables minima and second minima and 
// traversing over the array.
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
    int minima = INT_MAX;  
    int sec_minima = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<minima){
            minima = arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>minima && arr[i]<sec_minima){
            sec_minima = arr[i];
        }
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error finding the file"<<endl;
        return 1;
    }
    outputFile<<"Minima is "<<minima<<endl;
    outputFile<<"Second Minima is "<<sec_minima<<endl;
    outputFile.close();
    return 0;
}