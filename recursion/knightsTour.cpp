#include <iostream>
#include <vector>
using namespace std;

// CHECK KNIGHTS TOUR CONFIGURATION
// given a 2d array with integers representing the locations of a knight in sequential manner.
// starting point is the top left corner and each cell is visited only once. {0th position}
    // HINT: therefore, if we follow the path mentioned, we will reach the number (n^2 -1)
// to check if the config is correct or not, wrt to limitations in the movements of a knight 
// we use recursion and backtracking to solve this problem

bool knightour(vector<vector<int>> &grid, int val, int row, int col, int n){
    if(row<0 || row>=n || col<0 || col>=n) return false;
    // we check if the current location is the next integer
    if(grid[row][col]!=val) return false;

    //return true only if the curr val is the last integer
    if(grid[row][col]==((n*n) - 1)) return true;

    // we check different positions there after
    bool location_check = knightour(grid, val+1, row+1,col+2,n) ||
                        knightour(grid, val+1, row+2,col+1,n) ||
                        knightour(grid, val+1, row+2,col-1,n) ||
                        knightour(grid, val+1, row+1,col-2,n) ||
                        knightour(grid, val+1, row-1,col-2,n) ||
                        knightour(grid, val+1, row-2,col-1,n) ||
                        knightour(grid, val+1, row-2,col+1,n) ||
                        knightour(grid, val+1, row-1,col+2,n) ;
    return location_check;
}

int main(){

    vector<vector<int>> grid = {{0,5,2},{3,7,8},{6,1,4}};
    cout<<"is this a valid tour: "<<knightour(grid,0,0,0,grid.size());

    return 0;
}
// tc : O(8.power(n^2))
// sc : O(n^2)

//[[0,5,2],
// [3,7,8],
// [6,1,4]]