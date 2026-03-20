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

int summer(int &ans, TreeNode *root){
    if(root==nullptr) return 0;
    int lsum = max(0,summer(ans,root->left));
    int rsum = max(0,summer(ans,root->right));
    ans = max(ans,root->val + lsum + rsum);
    return root->val + max(lsum ,rsum);
}
int maxPathSum(TreeNode* root) {
    int ans = INT16_MIN;
    summer(ans,root);
    return ans;
}

int main(){
    return 0;
}