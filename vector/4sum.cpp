#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 4 SUM problem: given an array, provide 4 els that add up to a given target...
// to return an array of arrays with soln
// first we sort the array
// we run two nested loop for first two values, then we use two pointer method to get the other two
// we keep checking for duplicates in each loop...

int main(){
    vector <int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    vector <vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int ptr = j+1, end = n-1;
            while(ptr<end){
                long long num = (long long)nums[i]+(long long)nums[j]+(long long)nums[ptr]+(long long)nums[end];
                if(num==target){
                    ans.push_back({nums[i],nums[j],nums[ptr],nums[end]});
                    ptr++;end--;
                    while(ptr<end && nums[ptr]==nums[ptr-1]) ptr++;
                    while(ptr<end && nums[end]==nums[end+1]) end--;
                }else if(num<target){
                    ptr++;
                }else{
                    end--;
                }
            }
        }
    }

    for(vector<int> el : ans){
        for(int val:el){
            cout<<val<<",";
        }
        cout<<endl;
    }

    return 0;
}