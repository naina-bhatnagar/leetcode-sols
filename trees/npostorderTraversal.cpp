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

void postorder(vector<int>&ans, Node*root){
    if(root == nullptr) return;
    for(Node * child: root->children){
        postorder(ans, child);
    }
    ans.push_back(root->val);
}
vector<int> postorder(Node* root) {
    vector <int> ans;
    postorder(ans,root);
    return ans;
}

int main(){
    return 0;
}