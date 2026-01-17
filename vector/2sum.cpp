#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// given an unordered array and a target that is a sum of two elements --> return the index of those two elements...
pair<int,int> twoptr(vector<int>nums,int target);
// unordered map...
vector<int> hasher(vector<int>nums,int target){
    map <int,int> m;
    for(int i=0;i<nums.size();i++){
        int sec = target-nums[i];
        if(m.find(sec)!=m.end()){
            return {m[sec],i};
        }
        m[nums[i]] = i;
    }
    return {-1,-1};
}

int main(){
    vector<int>nums = {5,2,11,7,15};
    int target = 22;
    cout<<"the answer is: ";
    for(int el: hasher(nums,target)){
        cout<<el<<" ";
    }
    cout<<endl;
    
    return 0;
}

// appr1: two pointer method
// this method will not give the correct answer, as the array is now sorted...
// fix: store the value and original index data in a vector of arrays
pair<int,int> twoptr(vector<int>nums,int target){
    sort(nums.begin(),nums.end());
    int ptr=0, end=nums.size()-1;
    while(ptr<end){
        int currsum = nums[ptr]+nums[end];
        if(currsum==target){
            return {ptr,end};
        }else if(currsum>target){
            end--;
        }else{
            ptr++;
        }
    }
    return {-1,-1};
}