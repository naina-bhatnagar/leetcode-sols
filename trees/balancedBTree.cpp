#include <iostream>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int depth(TreeNode *root){
    if(root == nullptr) return 0;
    int ls = depth(root->left);
    int rs = depth(root->right);
    return 1 + max(ls,rs);
}
bool isBalanced(TreeNode* root) {
    if(root==nullptr) return true;
    int leftd = depth(root->left);
    int rightd = depth(root->right);
    if(abs(leftd - rightd) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
int main(){
    return 0;
}