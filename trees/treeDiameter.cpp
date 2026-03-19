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

int counter(int &ans, TreeNode* root){
    if(root == nullptr) return 0;
    int ls = counter(ans, root->left);
    int rs = counter(ans, root->right);
    ans = max(ans,ls+rs);
    return 1+max(ls,rs);
}
int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    counter(ans, root);
    return ans;
}

int main(){
    return 0;
}