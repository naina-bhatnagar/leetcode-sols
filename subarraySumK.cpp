#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// SUBARRAY SUM EQUALS K
// given an array of integers, find the number of subarrays that add up to k.
// Brute force: loop through the entire array once and select its end thru another loop and calculate the sum

int bruteForce(vector<int> nums, int k){
    int n = nums.size(), ans=0;
    for(int i=0;i<n;i++){
        int currsum = 0;
        for(int j=i;j<n;j++){
            currsum += nums[j];
            if(currsum == k){
                ans ++;
            }
        }
    }
    return ans;
}

int main(){
    vector <int> nums = {1,1,1};
    int k = 2;

    cout<<"Answer: "<<bruteForce(nums,k)<<endl;
    // prefix sum
    // define an array that stores the sum of all numbers until that index
    int n=nums.size(),ans=0;
    vector<int> presum(n);
    presum[0]=nums[0];
    for(int i=1;i<n;i++){
        presum[i] = presum[i-1]+nums[i];
    }

    // we are looking for the subarrays that add up to k
    // C1 ) the subarray from 0->m is equal to k
    // C2 ) some intermediate subarray {target = k-presum[current]}
    // for the case 2, we need a map to keep track of the number of times target has appeared in the past...
    unordered_map <int,int> m;
    for(int i=0;i<n;i++){
        if(presum[i]==k){
            ans++;
        }
        if(m.find(presum[i]-k)!=m.end()){
            ans += m[presum[i]-k];
        }
        m[presum[i]] ++;
    }

    cout<<"answer using prefix sum: "<<ans<<endl;

    return 0;
}