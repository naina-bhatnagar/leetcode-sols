#include <iostream>
#include <vector>
using namespace std;

// FIND DUPLICATES
// given an array with a single el that appears two or more times. all other els appear only once...
// if len of arr is n, its range is [1,n-1].
// APPROACH : slow-fast pointer
// we assume that our arr is a linked list. with idx as node and val as next_node pointer...
// then we use two pointers. one is slow, the other is fast,
// the slow pointer moves one val at a times, fast index skims thru 2 values...
// tc = O(n), sc = O(1)...

int main(){
    vector<int> nums = {2,5,7,8,9,1,9,6,3,4};

    int slow = nums[0];
    int fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow==fast);

    slow = nums[0];
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    cout<<"the answer is: "<<slow<<endl;

    return 0;
}