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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr && q==nullptr) return true;
    else if(p==nullptr || q==nullptr) return false;
    if(p->val != q->val) return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

int main(){
    return 0;
}