#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if(n<3) return 0;
    stack<int> s;
    int ans = 0;

    for (int i = 0; i < n; i++){
        int curr = height[i];
        while(!s.empty() && height[s.top()] < curr ){
            int valy = s.top();
            s.pop();

            if(s.empty()) break;

            int left = s.top();
            int right = i;

            int h = min(height[left],height[right]) - height[valy];
            int w = right - left - 1;
            ans += h*w;
        }
        s.push(i);
    }
    return ans;
}

int main(){
    vector <int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<< trap(height) <<endl;

    return 0;
}