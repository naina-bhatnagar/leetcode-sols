#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root == p || root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if(left != nullptr && right != nullptr) return root;
        return (left == nullptr ? right : left);
    }

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    TreeNode *p = root->left;
    TreeNode *q = root->right->right;
    //     1
    //   /   \
    // 2       3
    //       /   \
    //     4       5

    TreeNode *ans = lowestCommonAncestor(root,p,q);
    cout<<ans->val<<endl;

    return 0;
}