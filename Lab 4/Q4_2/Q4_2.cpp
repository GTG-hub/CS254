//Garima Upadhyay
//220001029

// Given two sorted arrays nums1 and nums2 of size m and n, respectively;
// return the median of the two sorted arrays.

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

void Median_func(int arr[], int l, int r, int k, int& a, int& b){
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
            return Median_func(arr, l,partitioned_index - 1,k, a, b);
        }else{
            return Median_func(arr,partitioned_index + 1,r, k, a, b);
        }
			
	}

	return;
}

// Function to find Median. Time Complexity: O(NlogN)
double findMedian(int arr[], int n){
	double ans;
    int a = -1, b = -1;
	if (n % 2 == 1) {
		Median_func(arr, 0, n - 1,n / 2, a, b);
		ans = b;
    }else {
		Median_func(arr, 0, n - 1,n / 2, a, b);
		ans = (a + b)*(1.0) / 2.0;
	}
    return ans;
}

//Function ot merge the two arrays. Time Complexity : O(m+n)
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

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    int arr[n];
    int brr[m];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    vector<int> v = merge_sorted_arrays(arr, n, brr,m);
    int c[v.size()];
    for(int i=0;i<v.size();i++){
        c[i]=v[i];
    }
    double ans = findMedian(c, v.size());
    cout<<ans<<endl;

}