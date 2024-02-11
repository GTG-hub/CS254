//Garima Upadhyay
//220001029


// Given an integer array nums and an integer k, return the kth largest element
// in the array.
// (Note that it is the kth largest element in the sorted order, not the kth distinct
// element.)


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){ //To return the position of the pivot element
	int lst = arr[r], i = l, j = l;
	while (j < r) {
		if (arr[j] < lst) {
			swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	swap(arr[i], arr[r]);
	return i;
}

int random_pivot_partition(int arr[], int l, int r){  //Picking a random pivot and partitioning
	int n = r - l + 1;
	int pivot = rand() % n;
	swap(arr[l + pivot], arr[r]);
	return partition(arr, l, r);
}

//Function to return the kth largest number
//Best Case Time Complexity:0(NlogN)
//Worst Case Time Complexity: O(N^2)
void kthlargest_func(int arr[], int l, int r, int k, int& a, int& b){
	if (l <= r) {
		int partitioned_index = random_pivot_partition(arr, l, r);

		if (partitioned_index == k) {
			b = arr[partitioned_index];
			if (a != -1){
                return;
            }
		}else if (partitioned_index == k - 1) {
			a = arr[partitioned_index];
			if (b != -1)
				return;
		}
		if (partitioned_index >= k){
            return kthlargest_func(arr, l,partitioned_index - 1,k, a, b);
        }else{
            return kthlargest_func(arr,partitioned_index + 1,r, k, a, b);
        }		
	}
	return;
}


int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a = -1;
    int b=-1;
    kthlargest_func(arr, 0, n-1,n-k, a ,b);
    cout<<b<<endl;
}