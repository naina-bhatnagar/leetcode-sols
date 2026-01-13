#include <iostream>
#include <vector>
using namespace std;

// SPIRAL MATRIX
// to print the elements of a 2d vector in spiral format
// TC : O(m*n) where m and n are the dimensions of the vector...

vector<int> spiralOrder(vector<vector<int>>mat) {
    vector<int> ans;
    int sr=0, sc=0, er=mat.size()-1, ec=mat[0].size()-1;
    while(sr<=er && sc<=ec){
        //right
        for(int j=sc;j<=ec;j++){
            ans.push_back(mat[sr][j]);
        }
        //downwards
        for(int i=sr+1;i<=er;i++){
            ans.push_back(mat[i][ec]);
        }
        //left
        for(int j=ec-1;j>=sc;j--){
            if(sr==er){
                break;
            }
            ans.push_back(mat[er][j]);
        }
        //upwards
        for(int i=er-1;i>sr;i--){
            if(sc==ec){
                break;
            }
            ans.push_back(mat[i][sc]);
        }
        sr++; sc++; er--; ec--;
    }
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout<<"Here's the single array with all the spiral elements:- "<<endl;
    for(int el:spiralOrder(mat)){
        cout<<el<<" ";
    }
    cout<<endl;

    return 0;
}