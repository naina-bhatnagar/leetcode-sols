#include <iostream>
#include <vector>
using namespace std;

int minimizeCost(int k, vector<int>& arr) {
    int n = arr.size();
    if(n==1 && k>=n) return abs(arr[0]-arr[n-1]);
    
    vector<int> path(n,INT16_MAX);
    path[0] = 0;
    
    for(int i=1;i<n;i++) {
        
        for(int j=i-1;j>i-k-1 && j>=0;j--){
            int curr = abs(arr[j]-arr[i]) + path[j];
            path[i] = min(path[i], curr);
        }
    }
    return path[n-1];
}