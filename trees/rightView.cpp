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

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root==nullptr) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=1;i<=n;i++){
            root = q.front();
            if(i==n) ans.push_back(root->val);
            if(root->left != nullptr) q.push(root->left);
            if(root->right != nullptr) q.push(root->right);
            q.pop();
        }
    }
    return ans;
}

int main(){
    return 0;
}