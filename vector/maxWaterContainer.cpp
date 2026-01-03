#include <iostream>
#include <vector>
using namespace std;

// TWO POINTER APPROACH...
// set the pointers to the starting and end of the array. calc the area and update the max area
// incr whichever length is lower...

// other uses of this approach
// 1. with strings : reversing, ifPalindrome

int main(){
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    int ptr = 0, end = height.size()-1, maxArea = 0;
    while(end>ptr){
        int currWidth = (end-ptr);
        int currHeight = min(height[ptr],height[end]);
        int currArea = currWidth * currHeight;
        maxArea = max(maxArea,currArea);
        height[ptr]<height[end] ? ptr++ : end--;
    }
    cout<<"Maximum water: "<<maxArea<<endl;
    return 0;
}