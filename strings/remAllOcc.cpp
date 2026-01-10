#include <iostream>
using namespace std;

// remove all occurances.
// given a string and a part, starting from left, we have to remove the first occ of the "part"...
// even after reaching the end we need to restart the search again to find the "part" in the ammended string

// we can use two STL functions:
// str.find(part)-->index of the first el of first occ
    // if not found, some out of range index is returned...
// str.erase(start_index,length)--> the part is removed in-place

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";

    while(s.length()>0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    cout<<s<<endl;

    return 0;
}