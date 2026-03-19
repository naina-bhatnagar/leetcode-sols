#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


vector<int> preorder(Node* root) {
    vector <int> ans;
    if(root== nullptr) return ans;
    stack <Node*> s;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();
        ans.push_back(root->val);
        for(int i = root->children.size()-1 ; i>=0; i--){
            if(root->children[i] == nullptr) continue;
            s.push(root->children[i]);
        }
    }
    return ans;
}

int main(){

    return 0;
}