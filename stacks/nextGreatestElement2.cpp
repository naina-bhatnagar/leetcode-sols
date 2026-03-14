#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack <int> s;

    for(int i = 2*n-1; i>=0; i--){
        int curr = nums[i%n];

        while(!s.empty() && s.top()<= curr) s.pop();

        ans[i%n] = (s.empty() ? -1 : s.top());
        s.push(curr);
    }
    return ans;
}

int main(){
    vector <int> nums = {1,2,3,4,3};
    vector <int> ans = nextGreaterElements(nums);
    for(int el: ans){
        cout<<el<<" ";
    }
    cout<<endl;

    return 0;
}