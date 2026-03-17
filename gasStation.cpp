#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int tgas = 0, tcost = 0, n = gas.size();
    for(int i=0; i<n; i++){
        tcost += cost[i];
        tgas += gas[i];
    }
    if(tcost>tgas) return -1;

    int ans = 0, currgas = 0;
    for(int i=0; i<n; i++){
        currgas += gas[i] - cost[i];
        if(currgas<0){
            ans = i+1;
            currgas = 0;
        }
    }

    return ans;
}

int main(){
    vector <int> gas = {1,2,3,4,5};
    vector <int> cost = {3,4,5,1,2};

    int ans = canCompleteCircuit(gas, cost);
    cout<<ans<<endl;

    return 0;
}