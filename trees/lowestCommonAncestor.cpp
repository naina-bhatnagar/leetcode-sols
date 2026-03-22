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

bool path(vector<TreeNode*>&ans,TreeNode *root,TreeNode *p){
    if(root == nullptr) return false;
    ans.push_back(root);
    if(root==p) return true;
    if(path(ans,root->left,p) || path(ans,root->right,p)) return true;
    ans.pop_back();
    return false;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *ans = root;
    vector<TreeNode*> l;
    path(l,root,p);
    vector<TreeNode*> r;
    path(r,root,q);
    int n = min(l.size(),r.size());
    for(int i=0; i<n; i++){
        if(l[i] == r[i]) ans = l[i];
        else break;
    }
    return ans;
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