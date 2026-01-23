#include <iostream>
#include <vector>
using namespace std;

void allpers(vector<int>&nums,vector<vector<int>> &ans, int n){
    if(n==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=n;i<nums.size();i++){
        swap(nums[i],nums[n]);
        allpers(nums,ans,n+1);
        swap(nums[i],nums[n]); // backtracking... return the original state
        // loop to the next element, and swap with it...
    }
}

// tc: n*n! {work in each call * total number of calls}
// sc: O(n! + n) = O( n! ) {n! : ans array}

int main(){
    vector <int> nums = {1,2,3};
    vector<vector<int>> ans;
    allpers(nums,ans,0);

    cout<<ans.size()<<endl;

    for(vector<int> el : ans){
        for(int val:el){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}