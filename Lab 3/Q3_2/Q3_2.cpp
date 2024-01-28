//Garima Upadhyay
//220001029
// Let x1, x2, . . . , xn be a set of integers.
// Give an O(n) divide-and-conquer algorithm to find the largest possible sum of
// a subsequence of consecutive items in the list.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxx(int a,int b,int c){
    return max(max(a,b), max(b,c));
}

int max_sum(int a[],int l,int r){           //Function to find the largest possible sum of a subsequence of consecutive items in the list
    if(l>r) return INT_MIN;
    if(l==r) return a[l];
    int m = l+(r-l)/2;
    int sum = 0;
    int l_sum = 0;
    int r_sum= 0;
    for(int i=m-1;i>=l;i--){
        sum+=a[i];
        if(sum> l_sum){
            l_sum = sum;
        }
    }
    sum = 0;
    for(int i=m+1;i<=r;i++){
        sum+=a[i];
        if(sum>r_sum){
            r_sum = sum;
        }
    }
    return maxx(max_sum(a,l,m-1),max_sum(a,m+1,r),l_sum+r_sum+a[m]);
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int sum = max_sum(arr,0,n-1);
    cout << "Largest possible sum of any subsequence is " << sum << endl;
    
}