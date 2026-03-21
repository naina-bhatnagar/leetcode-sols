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

void creator(vector<string>&ans, string &curr, TreeNode *root){
    if(root->left == nullptr && root->right == nullptr){
        curr += to_string(root->val);
        ans.push_back(curr);
        curr.pop_back();
        return;
    }
    curr += to_string(root->val); 
    curr += "->";
    int old_len = curr.size();
    if(root->left != nullptr){
        creator(ans,curr,root->left);
        curr.resize(old_len);
    }
    if(root->right != nullptr){
        creator(ans,curr,root->right); 
        curr.resize(old_len);
    }       
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string>ans;
    if(root == nullptr) return ans;
    string curr = "";
    creator(ans,curr,root);
    return ans;
}

int main(){
    return 0;
}