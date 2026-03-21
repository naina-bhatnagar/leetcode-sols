#include <iostream>
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

void leftmost(int &ans,int &maxlevel, int level, TreeNode *root){
    if(root == nullptr) return;
    if(level > maxlevel ){
        ans = root->val;
        maxlevel = level;
    }
    leftmost(ans,maxlevel,level+1,root->left);
    leftmost(ans,maxlevel,level+1,root->right);
}
int findBottomLeftValue(TreeNode* root) {
    if(root == nullptr) return -1;
    int ans = root->val, maxlevel = 0;
    leftmost(ans,maxlevel,0,root);
    return ans;
}

int main(){
    return 0;
}