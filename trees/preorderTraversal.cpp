#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// using iterative approach

vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    if(root==nullptr) return ans;
    stack <TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();
        ans.push_back(root->val);
        if(root->right != nullptr) s.push(root->right);
        if(root->left != nullptr) s.push(root->left);
    }
    return ans;
}

int main(){

    return 0;
}