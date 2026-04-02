#include <iostream>
#include <vector>
using namespace std;

int minCost(vector<int>& height) {
    int n = height.size();
    if(n<=1) return 0;
    int prev2 = 0, prev = abs(height[1]-height[0]);
    
    for(int i = 2;i<n;i++){
        int last = prev+ abs(height[i]-height[i-1]);
        int slast = prev2+ abs(height[i]-height[i-2]);
        int curr = min(last,slast);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}