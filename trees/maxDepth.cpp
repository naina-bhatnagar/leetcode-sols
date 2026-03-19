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

int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    int lsum = maxDepth(root->left);
    int rsum = maxDepth(root->right);
    return 1 + max(lsum,rsum);
}

int main(){
    return 0;
}