#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector <int> ans(nums1.size());
    unordered_map <int,int> m;
    stack <int> s;

    for(int i=nums2.size()-1; i>=0; i--){
        int curr = nums2[i];

        while(!s.empty() && s.top()<curr){
            s.pop();
        }

        if(s.empty()){
            m[curr] = -1;
        }else{
            m[curr] = s.top();
        }
        s.push(curr);
    }

    for(int i=0; i<nums1.size(); i++){
        ans[i] = m[nums1[i]];
    }

    return ans;
}

int main(){
    vector<int> arr;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    arr = nextGreaterElement(nums1,nums2);

    for(int el : arr){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}