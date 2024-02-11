//Garima Upadhyay
//220001029


// Given an array of integers A[ ], if i < j and A[i] > A[j] then the pair (i, j) is
// called the inversion of an array A[ ]. Write a program to find the total counts
// of inversion in an array A[ ].
// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <bits/stdc++.h>
using namespace std;
int merge(int arr[], int temp[], int left, int mid,
		int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
            k++;
            i++;
		}
		else {
			temp[k] = arr[j];
            k++;
            j++;
			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1){
        temp[k] = arr[i];
        k++;
        i++;
    }
		
	while (j <= right){
        temp[k] = arr[j];
        k++;
        j++;
    }
	for (i = left; i <= right; i++){
        arr[i] = temp[i];
    }
		

	return inv_count;
}
int _mergeSort(int arr[], int temp[], int left, int right){
	int mid, inv_count = 0;
	if (right > left) {
		mid = (right + left) / 2;
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}
int mergeSort(int arr[], int array_size){
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}


//Time complexity of above algorithm : O(NlogN)

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
    cout<<mergeSort(arr, n);
}