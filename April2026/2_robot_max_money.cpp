#include <iostream>
#include <vector>

using namespace std;

int explore(int r, int c, int k, vector<vector<int>>& coins, vector<vector<vector<int>>> &sums){
    if(r==0 && c==0){
        if (coins[0][0] < 0 && k > 0) return 0;
        return coins[0][0];
    } 
    if(r<0 || r>=coins.size() || c>=coins[0].size() || c<0) return -1e9;
    if(sums[r][c][k] != -1e9 - 7) return sums[r][c][k];

    int def = coins[r][c] + max(explore(r-1,c,k,coins,sums), explore(r,c-1,k,coins,sums));

    int pro = -1e9;
    if(coins[r][c] < 0 && k>0){
        pro = max(explore(r-1,c,k-1,coins,sums), explore(r,c-1,k-1,coins,sums));
    }

    sums[r][c][k] =  max(def,pro);
    return sums[r][c][k];
}
int maximumAmount(vector<vector<int>>& coins) {
    int n =coins.size(), m = coins[0].size();
    vector<vector<vector<int>>> sums(n, vector<vector<int>>(m, vector<int>(3, -1e9 - 7)));
    return explore(n-1,m-1,2,coins,sums);
}