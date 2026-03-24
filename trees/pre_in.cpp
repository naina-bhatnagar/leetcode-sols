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

TreeNode* build(vector<int>& preorder,unordered_map <int,int> &i, int pstart, int pend, int istart, int iend){
    if(pstart>pend || istart>iend) return nullptr;

    TreeNode* root = new TreeNode(preorder[pstart]);

    int n = i[root->val] - istart;
    
    root->left = build(preorder,i,pstart + 1, pstart + n, istart, i[root->val] - 1);
    root->right = build(preorder,i,pstart + n + 1, pend, i[root->val] + 1, iend);

    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
    unordered_map <int,int> i;
    int n = preorder.size();
    for(int j= 0;j<n;j++){
        i[inorder[j]] = j;
    }
    TreeNode* root = build(preorder,i,0,n-1,0,n-1);
    return root;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    //     1
    //   /   \
    // 2       3
    //       /   \
    //     4       5

    // add required code here

    // if a loop is required:

    // for (int x : path) {
    //     cout << x << " ";
    // }
    // cout << endl;

    return 0;
}