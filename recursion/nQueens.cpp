#include <iostream>
#include <vector>
using namespace std;

// N-QUEENS
// we try to find the locations of n queens in a n*n chess board such that no to queens can kill each other
// we try to return all the combinations that accomodate all the n queens...
// backtraking ensures that we explore all the combinations, so once a combination is found, the queens are removed

// "Okay, I found a solution with a Queen at Row 3, Col 1. Now let me remove her and see if 
// there's another solution with a Queen at Row 3, Col 2."

// tc: O(n!)

bool isSafe(vector<string>&board,int row,int col,int n){
    for(int i=0;i<n;i++){
        if(i!=row && board[i][col]=='Q') return false;
    }
    for(int r=row-1,c=col-1; r>=0 && c>=0; r--,c--){
        if(board[r][c]=='Q') return false;
    }
    for(int r=row-1,c=col+1; r>=0 && c<n; r--,c++){
        if(board[r][c]=='Q') return false;
    }
    return true;
}

void nqueens(vector<string>&board,int row,int n,vector<vector<string>>&ans){
    if(row==n){
        ans.push_back(board);
        return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col] = 'Q';
            nqueens(board,row+1,n,ans);
            board[row][col] = '.';
        }
    }
}


int main(){
    int n;
    cout<<"Choose n: ";
    cin>>n;
    vector<string> board(n,string(n, '.'));
    vector<vector<string>> ans;


    nqueens(board,0,n,ans);

    cout<<ans.size()<<endl;
    for(vector<string> el :ans){
        for(string val:el){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}