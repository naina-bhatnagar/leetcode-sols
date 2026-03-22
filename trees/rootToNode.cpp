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

bool creator(vector<int>&ans, int &tgt, TreeNode *root){
    if(root == nullptr) return false;

    ans.push_back(root->val);
    if(root->val == tgt) return true;

    if (creator(ans, tgt, root->left) || creator(ans, tgt, root->right)) return true;
    ans.pop_back();
    return false;
}
vector<int> rootToNode(TreeNode* root, int &tgt) {
    vector<int>ans;
    if(root == nullptr) return ans;
    creator(ans,tgt,root);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    int target = 5;
    vector<int> path = rootToNode(root, target);
    
    for (int x : path) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}