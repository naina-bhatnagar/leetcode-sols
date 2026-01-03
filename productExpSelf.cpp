#include <iostream>
#include <vector>
using namespace std;

// to find the product of all elements in an array except the number at the i th index...
// we first find the product of all elements to the left of each el. this can be called the prefix.
// then, we find the product at the right and call it suffix.
// the product is consecutive. the previous product is multiplied by the current ind int.
// the suffix is stored in an int to enhance space complexity.

int main(){
    vector <int> nums = {1,2,3,4};
    int n = nums.size();
    vector<int> ans(n,1);

    for(int i=1;i<n;i++){
        ans[i] = ans[i-1]*nums[i-1];
    }
    
    int val = 1;
    for(int i=n-2;i>=0;i--){
        val *= nums[i+1];
        ans[i] *= val;
    }

    cout<<"Answer: ";
    for(int val: ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}