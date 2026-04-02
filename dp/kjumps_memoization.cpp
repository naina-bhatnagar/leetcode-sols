#include <iostream>
#include <vector>
using namespace std;

int jump(int n, int &k, vector<int>& arr, vector<int>& path){
    if(n==0) return 0;
    if(path[n] != -1) return path[n];
    
    int curr = INT16_MAX;
    
    for(int i=n-1;i>n-k-1;i--){
        if(i < 0) break;
        int ijump = jump(i,k,arr,path) + abs(arr[n]-arr[i]);
        curr = min(curr,ijump);
    }
    
    path[n] = curr;
    return curr;
    
}
int minimizeCost(int k, vector<int>& arr) {
    int n = arr.size();
    
    vector<int> path(n,-1);
    
    return jump(n-1,k,arr,path);
    
}