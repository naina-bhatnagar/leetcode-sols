#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();

    vector<int>indices(n);
    for(int i = 0; i < n; i++) indices[i] = i;
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return positions[a] < positions[b];
    });

    for(int i=0;i<n;i++){
        if(directions[i] == 'L' ) healths[i] = -healths[i];
    }
    stack <pair<int,int>> s;

    for(int i=0;i<n;i++){
        int idx = indices[i];
        int currh = healths[idx];
        if(currh > 0){
            s.push({idx,currh});
            continue;
        }

        int m = s.size();
        bool addcurr = true;

        for(int i=0;i<m;i++){
            if(s.empty() || s.top().second < 0) break;

            int prev = s.top().first;
            int prevh = s.top().second;
            s.pop();
            if(currh+prevh == 0) {addcurr = false; break;}
            if(prevh > -currh){
                s.push({prev,prevh-1});
                addcurr = false;
                break;
            }
            currh ++;
        }
        if(addcurr) s.push({idx,currh});
    }
    int m = s.size();
    vector <pair<int,int>> p;
    while(!s.empty()){
        p.push_back(s.top());
        s.pop();
    }
    sort(p.begin(),p.end());
    vector <int> ans(m);
    for(int i = 0; i<m; i++){
        int curr = p[i].second;
        ans[i] = (curr<0) ? -curr : curr;
    }
    return ans;
}

int main(){
    vector <int> positions = {3,5,2,6};
    vector <int> healths = {10,10,15,12};
    string directions = "RLRL";

    vector<int> ans = survivedRobotsHealths(positions,healths,directions);
    for(int el : ans){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}