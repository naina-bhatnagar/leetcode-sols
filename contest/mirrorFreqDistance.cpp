#include <iostream>
#include <unordered_map>
using namespace std;

int mirrorFrequency(string s) {
    unordered_map <int,int> m;
    for(char el: s){            
        m[el] ++;
    }
    int ans = 0;
    for(char el : s){
        if(el<= '9'){
            ans += abs(m[el] - m['9'+'0'-el]);
            m[el] = 0; 
            m['9'+'0'-el] = 0;
        }
        if(el>='a'){
            ans += abs(m[el] - m['z'+'a'-el]);
            m[el] = 0; 
            m['z'+'a'-el] = 0; 
        }
    }
    return ans;
}