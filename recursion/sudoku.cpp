#include <iostream>
#include <vector>
using namespace std;

bool isAllowed(vector<vector<char>> &board, int row, int col,char n){
    for(int i=0;i<9;i++){
        if(board[row][i] == n) return false;
        if(board[i][col] == n) return false;
    }
    int rc = (row/3)*3;
    int cc = (col/3)*3;
    for(int r=rc;r<rc+3;r++){
        for(int c=cc;c<cc+3;c++){
            if(board[r][c]==n) return false;
        }
    }
    return true;
}

bool solv(vector<vector<char>> &board, int row, int col){
    if(row==9) return true;
    if(board[row][col]!='.'){
        // Move to the next cell immediately
            int nextRow = (col == 8) ? row + 1 : row;
            int nextCol = (col == 8) ? 0 : col + 1;
        return solv(board,nextRow,nextCol);
    }

    for(char n = '1'; n <= '9'; n++){
        if(isAllowed(board,row,col,n)){
            board[row][col] = n;

            // Move to the next cell immediately
            int nextRow = (col == 8) ? row + 1 : row;
            int nextCol = (col == 8) ? 0 : col + 1;

            if(solv(board,nextRow,nextCol)) return true;
            board[row][col] = '.';  
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solv(board,0,0);

    for(vector<char> el : board){
        for(char val:el){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// tc: O(9^{no.of empty cells})