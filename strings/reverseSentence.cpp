#include <iostream>
#include <algorithm>
using namespace std;

// STRING REVERSAL 
// to reverse the sequence of words in a string
// eg) this is cpp --> cpp is this
// reverse the string and identify the words. re-reverser them to get the word. append that word to the variable ans;
// make sure an empty space is added between all the words and all extra whitespaces are deleted...
int main(){
    string s = "the sky is blue";

    int n = s.length();
    string ans;

    reverse(s.begin(),s.end());

    for(int i=0;i<n;i++){
        string word = "";
        while(i<n && s[i]!=' '){
            word += s[i++];
        }

        reverse(word.begin(),word.end());
        if(word.length()>0){
            ans += " "+word;
        }
    }

    cout<<ans.substr(1)<<endl;

    return 0;
}