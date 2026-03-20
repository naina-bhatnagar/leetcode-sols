#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v){
        val = v;
        left = right = nullptr;
    }
};

bool sym(TreeNode *l, TreeNode *r){
    if(l == nullptr && r == nullptr) return true;
    else if(l == nullptr || r == nullptr) return false;

    return (l->val == r->val) && sym(l->left,r->right) && sym(l->right,r->left);
}
bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return sym(root->left,root->right);
}

int main(){
    return 0;
}