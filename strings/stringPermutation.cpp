#include <iostream>
using namespace std;

// STRING PERMUTATIONS
// given two strings. we have to figure out if any permutation of the first string appears in the second one.
// we only have lower case letters in both the arrays

// APPROACH
// we create an array that stores the frequency of all the possible letters {from a to z}
// we iterate over the second array using a window. 
// we check if the frequencies of both the window and first string match, if yes, return true

// if the ques deals with other elements like numbers and symbols and numbers, we use a unordered map {hash table}
bool isSame(int arr1[],int arr2[]){
    for(int i=0;i<26;i++){
        if(arr1[i]!=arr2[i]){
            return false;
        }
    }
    return true;
}


int main(){
    string s1 = "na";
    string s2 = "jnsanfoibanfaow";

    int freq[26] = {0};
    for(char ch : s1){
        freq[ch-'a'] ++;
    }
    bool ans=false;
    int wsize = s1.length();

    for(int i=0;i<s2.length();i++){
        int widx = 0, idx=i;
        int wfreq[26] = {0};

        while(widx<wsize && idx<s2.length()){
            wfreq[s2[idx]-'a']++;
            widx++;idx++;
        }
        if (isSame(freq,wfreq)){
            ans = true;
            break;
        }
    }

    if(ans){
        cout<<"a permutation was found"<<endl;
    }else{
        cout<<"no permutation was found"<<endl;
    }
    return 0;
}