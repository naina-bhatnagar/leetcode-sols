#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int>nums = {-1,0,1,2,-1,-4};

    vector<vector<int>>ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i = 0; i<n ; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j = i+1, k = n-1;
        while(j<k){
            int currsum = nums[i]+nums[j]+nums[k];
            if(currsum == 0){
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;k--;

                while(j<k && nums[j]==nums[j-1]) j++;
            }else if(currsum<0){
                j++;
            }else{
                k--;
            }
        }
    }

    for(auto el:ans){
        for(int val:el){
            cout<<val<<" ";
        }
        cout<<endl;
    }


    return 0;
}