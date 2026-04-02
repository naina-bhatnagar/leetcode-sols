#include <iostream>
#include <vector>
using namespace std;

int explore(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& sums){
    if(r==0 && c==0) return grid[0][0];
    if(r<0 || r>=grid.size() || c>=grid[0].size() || c<0) return INT16_MAX;
    if(sums[r][c] != -1) return sums[r][c];

    sums[r][c] = grid[r][c] + min(explore(r-1,c,grid,sums), explore(r,c-1,grid,sums));
    return sums[r][c];
}
int minPathSum(vector<vector<int>>& grid) {
    int n =grid.size(), m = grid[0].size();
    vector<vector<int>> sums(n, vector<int>(m, -1));
    return explore(n-1,m-1,grid,sums);
}