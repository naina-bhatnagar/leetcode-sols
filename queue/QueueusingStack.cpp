#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack <int> q1;
    stack <int> *curr;
    stack <int> q2;
    stack <int> *other;
    MyQueue() {
        curr = &q1;
        other = &q2;
    }
    
    void push(int x) {
        curr->push(x);
    }
    
    int pop() {
        if(curr->empty()) return -1;
        while(!curr->empty()){
            other->push(curr->top());
            curr->pop();
        }
        int ans = other->top();
        other->pop();
        while(!other->empty()){
            curr->push(other->top());
            other->pop();
        }
        return ans;
    }
    
    int peek() {
        if(curr->empty()) return -1;
        while(!curr->empty()){
            other->push(curr->top());
            curr->pop();
        }
        int ans = other->top();
        while(!other->empty()){
            curr->push(other->top());
            other->pop();
        }
        return ans;
    }
    
    bool empty() {
        return curr->empty();
    }
};

int main(){
    return 0;
}