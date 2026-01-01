#include <iostream>
#include <vector>
using namespace std;

// Pair sum
// given a target, return the index pair in a 'sorted' array that sum up to the target

// we use two pointer approach, 

int main(){
    vector<int>vec = {2,7,11,15};
    int target;
    cout<<"Target: ";
    cin>>target;
    
    int n = vec.size();
    int start=0, end=n-1, sum = 0; // one pointer at the start, other at the end. 
    vector<int> result;

    while(start<end){
        sum =vec[start]+vec[end];
        if(sum>target){ // curr sum is greater, reduce the end index
            end--;
        }else if(sum<target){ // curr sum is less, incr the start idx
            start++;
        }else{
            result = {start,end};
            for(int val:result){
                cout<<val<<" ";
            }
            cout<<endl;
            return 0;
        }
    }

    result = {0,0};

    for(int val:result){
        cout<<val<<" ";
    }

    cout<<endl;
    return 0;
}