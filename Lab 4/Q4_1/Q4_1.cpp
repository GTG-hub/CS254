//Garima Upadhyay
//220001029


// Given an array of integers A[ ], if i < j and A[i] > A[j] then the pair (i, j) is
// called the inversion of an array A[ ]. Write a program to find the total counts
// of inversion in an array A[ ].


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Function to return the number of elements smaller than the given number by setting the current number as pivot
int partition(int arr[], int l, int r, int pivot){      //To return the position of the pivot element
	int lst = pivot, i = l-1, j = l;
	while (j < r) {
		if (arr[j] < lst) {
			i++;
		}
		j++;
	}
	return i;
}

void counts_of_inversion(int arr[], int n){
    int ans =0;
    for(int i=0;i<n-1;i++){
        ans += partition(arr, i+1, n, arr[i])-i;
    }
    cout<<ans<<endl;
}
//Time complexity of above algorithm : O(N^2)

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    counts_of_inversion(arr, n);
}