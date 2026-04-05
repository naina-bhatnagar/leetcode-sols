#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> findGoodIntegers(int n) {
    unordered_map<int,int> m;
    for(int i=1;i*i*i < n;i++){
        m[i] = i*i*i;
    }
    unordered_map<int,int> cubes;
    for(int i=1;i*i*i < n;i++){
        for(int j = i;j*j*j < n; j++){
            int curr = m[i]+m[j];
            cubes[curr] ++;
        }
    }
    vector<int> ans;
    for(auto pair: cubes){
        int el = pair.first;
        int count = pair.second;
        if(count>=2 && el<=n){
            ans.push_back(el);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}