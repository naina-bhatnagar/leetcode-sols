#include <iostream>
#include <vector>
using namespace std;

// SEARCH A 2D MATRIX
// given a 2d matrix with el filled in incr order.
// to find if a target element is present in the matrix or not...

bool searchMatrix(vector<vector<int>>matrix, int target) {
    int ptr = 0,end = matrix.size() - 1;
    while(ptr<=end){
        int midrow = ptr + (end-ptr)/2;
        int col = matrix[midrow].size()-1;
        if(target>=matrix[midrow][0] && target<=matrix[midrow][col]){
            int st =0, next = col;
            while(st<=next){
                int mid = st + (next-st)/2;
                if(matrix[midrow][mid]==target){
                    return true;
                }else if(target>matrix[midrow][mid]){
                    st = mid+1;
                }else{
                    next = mid-1;
                }
            }
            return false;
        }else if(target>matrix[midrow][col]){
            ptr = midrow + 1;
        }else{
            end = midrow - 1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 34;

    cout<<"if the given element is in the 2d vector: "<<searchMatrix(mat,target)<<endl;


    return 0;
}