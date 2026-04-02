#include <iostream>
#include <vector>
using namespace std;

int firstMatchingIndex(string s) {
    for(int i=0; i<= s.length(); i++){
        int j = s.length() - i - 1;
        if(i<0 || j>= s.length()) continue;
        if(s[i] == s[j]) return i;
    }
    return -1;
}