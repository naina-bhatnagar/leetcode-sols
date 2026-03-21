#include <iostream>
#include <vector>
#include <queue>
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

void right(vector<int>&ans,int level,TreeNode *root){
    if(root == nullptr) return;
    if(level == ans.size()) ans.push_back(root->val);
    right(ans,level+1,root->right);
    right(ans,level+1,root->left);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    right(ans,0,root);
    return ans;
}

int main(){
    return 0;
}