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

int checker(TreeNode *root){
    if(root == nullptr) return 0;
    int ls = checker(root->left);
    if(ls==-1) return -1;
    int rs = checker(root->right);
    if(rs==-1) return -1;
    if (abs(ls - rs) > 1) return -1;
    return 1 + max(ls,rs);
}
bool isBalanced(TreeNode* root) {
    return checker(root) != -1;
}
int main(){
    return 0;
}