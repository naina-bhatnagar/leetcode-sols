#include <iostream>
#include <vector>
using namespace std;

int ans(vector <char> &chars){
    int n=chars.size(),idx=0;
    if(n==1){
        return 1;
    }

    for(int i=0;i<n;){
        char ch = chars[i];
        int count = 0;

        while(i<n && chars[i]==ch){
            count++;i++;
        }
        if(count==1){
            chars[idx++] = ch;
        }else{
            chars[idx++] = ch;
            string num = to_string(count);
            for(char el:num){
                chars[idx++] = el;
            }
        }
    }
    chars.resize(idx);
    return idx;
}

int main(){
    vector<char> chars= {'a','a','b','b','b','b','c','c','c'};
    cout<<ans(chars)<<endl;
    for(char el: chars){
        cout<<el<<" ";
    }
    cout<<endl;

    return 0;
}