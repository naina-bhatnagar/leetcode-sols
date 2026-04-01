#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int>s;
    for(int i=0; i<asteroids.size();i++){
        int el = asteroids[i];
        if(el>0 || s.empty()){
            s.push(el);
            continue;
        }
        int n = s.size();
        bool addcurr = true;

        for(int j=0;j<n;j++){
            if(s.top()<0) break;
            int prev = s.top();
            s.pop();
            if(prev+el == 0) {addcurr = false; break;}
            if(prev> -el) {
                s.push(prev);
                addcurr = false;
                break;
            }
        }
        if(addcurr) s.push(el);
    }
    int n = s.size();
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[i] = s.top();
        s.pop();
    }
    return ans;
}


int main(){
    vector <int> asteroids = {3,5,-6,2,-1,4};
    vector <int> ans = asteroidCollision(asteroids);
    for(int el:ans){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}