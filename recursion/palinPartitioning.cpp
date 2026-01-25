#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// to partition a string, where each part must be a palindrome
// tc: O( n* 2^n) => O( 2^n )

bool isPalin(string s){
    string temp = s;
    reverse(s.begin(),s.end());
    if(s==temp) return true;
    return false;
}
void checker(string s, vector<string> &ans, vector<vector<string>>&solution){
    if(s.length()==0){
        solution.push_back(ans);
        return;
    }
    for(int i=0;i<s.length(); i++){
        string currpart = s.substr(0,i+1);
        if(isPalin(currpart)){
            ans.push_back(currpart);
            checker(s.substr(i+1),ans,solution);
            ans.pop_back();
        }
    }
    return;
}

int main(){
    string s = "aab";
    vector<vector<string>> solution;
    vector<string> ans;
    checker(s,ans,solution);

    for(vector<string> el : solution){
        for(string val:el){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}