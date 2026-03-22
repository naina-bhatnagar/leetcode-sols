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