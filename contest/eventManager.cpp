#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class EventManager {
public:
    unordered_map <int,int> m;
    set <pair<int,int>> s;
    EventManager(vector<vector<int>>& events) {
        for(vector<int> el : events){
            m[el[0]] = el[1];
            s.insert({el[1],-el[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        s.erase({m[eventId],-eventId});
        m[eventId] = newPriority;
        s.insert({newPriority,-eventId});
    }
    
    int pollHighest() {
        if(s.empty()) return -1;
        pair<int,int> pr = *s.rbegin();
        int ans = -pr.second;
        s.erase(prev(s.end()));
        m.erase(ans);
        return ans;
    }
};