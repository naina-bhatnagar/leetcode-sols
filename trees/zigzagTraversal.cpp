#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue <TreeNode*> s;
    s.push(root);
    int l = 1;
    while(!s.empty()){
        int n = s.size();
        vector <int> level;
        for(int i=0; i<n; i++){
            root = s.front();
            s.pop();
            if(root->left != nullptr) s.push(root->left);
            if(root->right != nullptr) s.push(root->right);
            level.push_back(root->val);
        }
        if(l%2==0){
            reverse(level.begin(),level.end());
        }
        ans.push_back(level);
        l++;
    }
    return ans;
}

int main(){
    return 0;
}