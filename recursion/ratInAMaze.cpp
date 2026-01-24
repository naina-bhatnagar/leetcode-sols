#include <iostream>
#include <vector>
using namespace std;

// given a maze
// find all the paths from (0,0) till (n-1,n-1)
// no cell can be used twice... only traverse through 1s, u cannot pass thru 0s...

// tc: O(4^{n*m}) ; in worst case, we need to check all the cells of the grid and each of those cells have 4 possibilities...

void route(vector<vector<int>> &maze, int row, int col, int n, int m, string &ans, vector<string> &solution){
    if(row==n-1 && col==m-1){
        solution.push_back(ans); 
        return;
    }
    if(row<0 || row>=n || col<0 || col>=m) return;
    if(maze[row][col]==0) return;

    maze[row][col] = 0;

    ans.push_back('D');
    route(maze,row+1,col,n,m,ans,solution);
    ans.pop_back();
    ans.push_back('L');
    route(maze,row,col-1,n,m,ans,solution);
    ans.pop_back();
    ans.push_back('R');
    route(maze,row,col+1,n,m,ans,solution);
    ans.pop_back();
    ans.push_back('U');
    route(maze,row-1,col,n,m,ans,solution);
    ans.pop_back();

    maze[row][col] = 1;

    return;
}

int main(){
    vector<vector<int>> maze = {
    {1, 1, 1, 1},
    {0, 0, 0, 1},
    {1, 1, 1, 1}, // Path comes back to the left here!
    {1, 0, 0, 0},
    {1, 1, 1, 1}  // Finally reaches the end
};
    vector<string> solutions;
    string ans;
    int n = maze.size(), m=maze[0].size();
    route(maze,0,0,n,m,ans, solutions);

    for(string el:solutions){
        cout<<el<<endl;
    }

    return 0;
}