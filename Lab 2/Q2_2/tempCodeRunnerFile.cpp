void inplace_merge(int arr[], int l, int m, int r){
    int b = m+1;
    if(arr[m]<=arr[b]){
        return;
    }
    while(l<=m && b<=r){
        if(arr[l]<=arr[b]){
            l++;
        }else{
            int val = arr[b];
            int i = b;
            while(i!=l){
                arr[i]= arr[i-1];
                i--;
            }
            arr[l]= val;
            l++;
            m++;
            b++;
        }
    }
}