#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    stack <TreeNode*> s;
    vector <int> ans;
    TreeNode* node = root;
    while(true){
        if(node!=nullptr){
            s.push(node);
            node = node->left;
        }else{
            if(s.empty()) return ans;
            node = s.top();
            s.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}

int main(){
    return 0;
}