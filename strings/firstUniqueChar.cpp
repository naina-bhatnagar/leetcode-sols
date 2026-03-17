#include <iostream>
#include <vector>
using namespace std;

int firstUniqChar(string s) {
    vector <int> freq(26,0);

    for(int i=0; i<s.length(); i++){
        freq[s[i]-'a'] ++;
    }
    
    for(int i=0; i<s.length(); i++){
        if(freq[s[i]-'a'] == 1) return i;
    }
    return -1;
}

int main(){
    string s = "aabbccddf";
    cout<<firstUniqChar(s)<<endl;
    return 0;
}