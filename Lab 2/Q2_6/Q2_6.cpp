#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//We can solve this question by finding the median as in ques 4 and then swapping the last indexed element with median element and then 
// implementing normal quicksort.
int partition(int arr[], int l, int r){   //To return the position of the pivot element
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

// Function to find Median
int findMedian(int arr[], int n){
	int ans, a = -1, b = -1;
	if (n % 2 == 1) {
		Median_func(arr, 0, n - 1,n / 2, a, b);
		ans = b;
    }else {
		Median_func(arr, 0, n - 1,n / 2, a, b);
		ans = max(a,b);        //Almost median
	}
    return ans;
}

void quickSort(int arr[],int low,int high)
{
    if(low<high){
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
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

    int c = findMedian(arr,n);
    swap(arr[c], arr[n-1]);    //Swap the median element with the last index element for having the pivot element as almost median
    quickSort(arr, 0 , n-1);
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error finding the file"<<endl;
        return 1;
    }

    outputFile<<"Sorted array is"<<endl;
    for(int i=0;i<n;i++){
        outputFile<<arr[i]<<" ";
    }
    outputFile<<endl;
    outputFile.close();
    return 0;
}