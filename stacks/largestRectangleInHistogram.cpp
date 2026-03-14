#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size(), ans = 0;
    stack<int> s;
    vector<int> left(n);
    vector<int> right(n);

    // left lowest element
    for (int i = 0; i < n; i++) {
        int curr = heights[i];

        while (!s.empty() && heights[s.top()] >= curr) s.pop();
        left[i] = (s.empty() ? -1 : s.top());
        s.push(i);
    }
    while(!s.empty()) s.pop();

    // right lowest element
    for (int i = n-1; i >= 0; i--) {
        int curr = heights[i];

        while (!s.empty() && heights[s.top()] >= curr) s.pop();
        right[i] = (s.empty() ? n : s.top());
        s.push(i);
    }

    for(int i=0; i<n; i++){
        int w = right[i] - left[i] - 1;
        int curr_area = heights[i] * w;
        ans = max(ans, curr_area);
    }

    return ans;
}

int main(){
    vector <int> heights = {2,1,5,6,2,3};
    cout<<largestRectangleArea(heights)<<endl;

    return 0;
}