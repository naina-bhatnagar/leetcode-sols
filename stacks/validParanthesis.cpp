#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack <char> st;
    for(char el : s){
        if(el == '(' || el == '{' || el == '[') st.push(el);
        else{
            if(st.empty()) return false;
            if((el == ')' && st.top() == '(') ||
                (el == '}' && st.top() == '{') ||
                (el == ']' && st.top() == '[')) {
                    st.pop();
            }else{
                return false;
            }
        }
    }
    return st.size() == 0;
}

int main(){
    string s ="{[()]}";
    string s1 ="{[()}";
    cout<<"if the string has valid seq of closed paranthesis: "<<isValid(s)<<endl;
    cout<<"if the string has valid seq of closed paranthesis: "<<isValid(s1)<<endl;
    return 0;
}