//Garima Upadhyay
//220001029

// Given two sorted arrays nums1 and nums2 of size m and n, respectively;
// return the median of the two sorted arrays.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;




double findMedian(vector<int>& A, vector<int>& B)
{
    int n = A.size();
    int m = B.size();
    if (n > m){
        return findMedian(B, A); 
    }
    int lo = 0;
    int hi = n;
    int realmidinmergedarray = (n + m + 1) / 2;
 
    while (lo<= hi) {
        int mid = (lo + hi) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA = (leftAsize > 0)? A[leftAsize - 1]: INT_MIN; 
        int leftB = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? B[leftBsize] : INT_MAX;

        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB) {
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
            
    }
    return 0.0;
}
//Time complexity: O(logN)

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    vector<int> brr(m);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    double ans = findMedian(arr, brr);
    cout<<ans<<endl;

}