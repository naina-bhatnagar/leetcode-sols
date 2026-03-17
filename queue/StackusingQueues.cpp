#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> *curr;

    MyStack() {
        curr = &q1;
    }
    
    void push(int x) {
        curr->push(x);
    }
    
    int pop() {
        if(curr->empty()) return -1;
        for(int i=1; i<curr->size(); i++){
            curr->push(curr->front());
            curr->pop();
        }
        int ans = curr->front();
        curr->pop();
        return ans;
    }
    
    int top() {
        if(curr->empty()) return -1;
        return curr->back();
    }
    
    bool empty() {
        return curr->empty();
    }
};

int main(){
    return 0;
}