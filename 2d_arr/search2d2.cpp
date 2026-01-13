#include <iostream>
#include <vector>
using namespace std;

// SEARCH A MATRIX 2
// given a matrix with vals incr down a row, and across cols.
// to determine if a target is present in the matrix or not...
// TC : O(n+m)

bool searchmat(vector<vector<int>>mat,int target){
    int n=mat.size(), m=mat[0].size();
    int r=0,c=m-1;
    while(r<n && c>=0){
        if(mat[r][c]==target){
            return true;
        }else if(mat[r][c]<target){
            r++;
        }else{
            c--;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 3;

    cout<<"if the target value is present in the vector: "<<searchmat(mat,target)<<endl;

    return 0;
}