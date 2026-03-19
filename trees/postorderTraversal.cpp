#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector <int> ans;
    if(root == nullptr) return ans;
    stack <TreeNode*> s1;
    s1.push(root);
    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        if(root->left != nullptr) s1.push(root->left);
        if(root->right != nullptr) s1.push(root->right);
        ans.push_back(root->val);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    return 0;
}