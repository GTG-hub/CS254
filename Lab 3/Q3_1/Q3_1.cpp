//Garima Upadhyay
//220001029
//Perform matrix multiplication using Divide & Conquer.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//Funcion to print the matrix. Time Complexity : O(n^2)
void print(vector<vector<int> > mat,int row_i,int col_i,int length,int width){
    for(int i=row_i;i<(row_i+length);i++){
        for(int j=col_i;j<(col_i+width);j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void transform(vector<vector<int>> &mat,int max,int m,int n ){   //Function to transform any matrix to nearest power of 2
    int pow = 0;
    while(max>(1<<pow)){
        pow++;
    }
    max = 1<<pow;
    for(int i=0;i<max;i++){
        if(i<m){
            for(int j=n;j<max;j++){
                mat[i].push_back(0);
            }
        }else{
            vector<int> v(max);
            mat.push_back(v);
        }
    }
   
}

//Mat_add function is used to add two matrices Time Complexity: O(n^2)
void mat_add(vector<vector<int> > m1,vector<vector<int> > m2,vector<vector<int> >& ans,int row_i,int col_i,int length,int width){
    for(int i=row_i;i<(row_i+length);i++){
        for(int j=col_i;j<(col_i+width);j++){
            ans[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

//Mat_mult is for multiplication of matrices Time Complexity: O(n^3)
// T(n) = 8*T(n/2) + n*c;
//From masters theorem we get time complexity as O(n^(3))

vector<vector<int>> mat_mult(vector<vector<int> > m1,vector<vector<int> > m2,int row_i,int col_i,int row_i1,int col_i1,int row_i2,int col_i2,int length,vector<vector<int> >& ans_mat){
    if(length==1){
        ans_mat[row_i][col_i] = m1[row_i1][col_i1]*m2[row_i2][col_i2];
        return ans_mat;
    }else if(length==2){
        ans_mat[row_i][col_i] = m1[row_i1][col_i1]*m2[row_i2][col_i2] + m1[row_i1][col_i1+1]*m2[row_i2+1][col_i2];
        ans_mat[row_i][col_i+1] = m1[row_i1][col_i1]*m2[row_i2][col_i2+1] + m1[row_i1][col_i1+1]*m2[row_i2+1][col_i2+1];
        ans_mat[row_i+1][col_i] = m1[row_i1+1][col_i1]*m2[row_i2][col_i2] + m1[row_i1+1][col_i1+1]*m2[row_i2+1][col_i2];
        ans_mat[row_i+1][col_i+1] = m1[row_i1+1][col_i1]*m2[row_i2][col_i2+1] + m1[row_i1+1][col_i1+1]*m2[row_i2+1][col_i2+1];
        return ans_mat;
        
    }
    mat_add(mat_mult(m1,m2,row_i,col_i,row_i1,col_i1,row_i2,col_i2,length/2,ans_mat),mat_mult(m1,m2,row_i,col_i,row_i1,col_i1+length/2,row_i2+length/2,col_i2,length/2,ans_mat),ans_mat,row_i,col_i,length/2,length/2);
    mat_add(mat_mult(m1,m2,row_i,col_i+length/2,row_i1,col_i1,row_i2,col_i2+length/2,length/2,ans_mat),mat_mult(m1,m2,row_i,col_i+length/2,row_i1,col_i1+length/2,row_i2+length/2,col_i2+length/2,length/2,ans_mat),ans_mat,row_i,col_i+length/2,length/2,length/2);
    mat_add(mat_mult(m1,m2,row_i+length/2,col_i,row_i1+length/2,col_i1,row_i2,col_i2,length/2,ans_mat),mat_mult(m1,m2,row_i+length/2,col_i,row_i1+length/2,col_i1+length/2,row_i2+length/2,col_i2,length/2,ans_mat),ans_mat,row_i+length/2,col_i,length/2,length/2);
    mat_add(mat_mult(m1,m2,row_i+length/2,col_i+length/2,row_i1+length/2,col_i1,row_i2,col_i2+length/2,length/2,ans_mat),mat_mult(m1,m2,row_i+length/2,col_i+length/2,row_i1+length/2,col_i1+length/2,row_i2+length/2,col_i2+length/2,length/2,ans_mat),ans_mat,row_i+length/2,col_i+length/2,length/2,length/2);

    return ans_mat;
}


//Time Complexity of the algorithm : O(n^3)
int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b==c){
        vector<vector<int> > m1(a,vector<int>(b,0)),m2(c,vector<int>(d,0)),ans(a,vector<int>(d,0));
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cin >> m1[i][j];
            }
        }
        for(int i=0;i<c;i++){
            for(int j=0;j<d;j++){
                cin >> m2[i][j];
            }
        }
        int maxx = max(max(a,b),max(c,d));
        transform(ans,maxx,a,d);
        transform(m1,maxx,a,b);
        transform(m2,maxx,c,d);
        ans = mat_mult(m1,m2,0,0,0,0,0,0,ans.size(),ans);
        print(ans,0,0,a,d);
        cout<<endl;
    }else{
        cout<<"Invalid input "<<endl;
    }
}