#include <iostream>
using namespace std;

int rowmaxsum(int mat[][3],int row,int col){
    int currsum=0,maxsum = INT32_MIN;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            currsum += mat[i][j];
        }
        maxsum = max(maxsum,currsum);
        currsum=0;
    }
    return maxsum;
}

int diagsum(int mat[][3],int row){
    int sum=0;
    for(int i=0;i<row;i++){
        sum+=mat[i][i];
        if(row-i-1==i){
            continue;
        }
        sum+=mat[row-i-1][i];
    }
    return sum;
}

int main(){
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int row=3, col=3;
    cout<<"the maximum sum across any row is: "<<rowmaxsum(mat,row,col)<<endl;
    cout<<"the diagonal sum is: "<<diagsum(mat,row)<<endl;

    return 0;
}