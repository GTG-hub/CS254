#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> merge_sorted_arrays(int A[],int m,  int B[], int n){
    vector<int> C;
    int i=0, j=0, k=0;
    while(k<m+n){
        if(i==m || B[j]<=A[i]){
            C.push_back(B[j]);
            j++;
        }else if(j==n || B[j]> A[i]){
            C.push_back(A[i]);
            i++;
        }
        k++;
    }
    return C;

}

vector<int> sorted_array_for_AunionB(int A[], int m, int B[] , int n){
    vector<int> C;
    int i=0, j=0;
    while (i<m || j<n){
        if(A[i]<B[j]){
            C.push_back(A[i]);
            i++;
        }else if(B[j]<A[i]){
            C.push_back(B[j]);
            j++;
        }else{
            C.push_back(A[i]);
            i++;
            j++;
        }
    }
    return C;
}
vector<int> sorted_array_for_AintersectionB(int A[], int m, int B[] , int n){
    vector<int> C;
    int i=0, j=0;
    while (i<m && j<n){
        if(A[i]<B[j]){
            i++;
        }else if(B[j]<A[i]){
            j++;
        }else{
            C.push_back(A[i]);
            i++;
            j++;
        }
    }
    return C;
}

int main(){
    ofstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error finding the file"<<endl;
        return 1;
    }
    int m = rand()%10 +1;
    int n = rand()%10 +1;
    inputFile<<m<<" "<<n<<endl;
    for(int i=0;i<m;i++){
        inputFile<<i<<" ";
    }
    inputFile<<endl;
    for(int i=0;i<n;i++){
        inputFile<<i<<" ";
    }
    inputFile<<endl;
    inputFile.close();
    ifstream inputFileRead("input.txt", ios::in);
    if(!inputFileRead.is_open()){
        cerr<<"Error finding the file"<<endl;
        return 1;
    }
    int a;
    int b;
    
    inputFileRead>>a>>b;
    int arr[a];
    int brr[b];
    for(int i=0;i<a;i++){
        inputFileRead>>arr[i];
    }
    for(int i=0;i<b;i++){
        inputFileRead>>brr[i];
    }
    inputFileRead.close();
    vector<int> aa = merge_sorted_arrays(arr, a, brr, b);
    vector<int> ab = sorted_array_for_AunionB(arr, a, brr, b);
    vector<int> ac = sorted_array_for_AintersectionB(arr, a, brr, b);
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error finding the file"<<endl;
        return 1;
    }
    outputFile<<"Answer after merging two sorted arrays"<<endl;
    for(int i=0;i<aa.size();i++){
        outputFile<<aa[i]<<" ";
    }
    outputFile<<endl;
    outputFile<<"Answer for showing the sorted array of A union B"<<endl;
    for(int i=0;i<ab.size();i++){
        outputFile<<ab[i]<<" ";
    }
    outputFile<<endl;
    outputFile<<"Answer for showing the sorted array for A intersection B"<<endl;
    for(int i=0;i<ac.size();i++){
        outputFile<<ac[i]<<" ";
    }
    outputFile<<endl;
    outputFile.close();
    return 0;

}