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

void fission(vector<int> &ans, TreeNode* target, int k,unordered_map <TreeNode*, bool> &visited, unordered_map <TreeNode*, TreeNode*> &parent){
        if(target == nullptr || k<0 || visited[target]) return;
        
        if( k==0){
            ans.push_back(target->val);
            visited[target] = true;
            return;
        }
        visited[target] = true;
        fission(ans,target->left,k-1,visited,parent);
        fission(ans,target->right,k-1,visited,parent);
        fission(ans,parent[target],k-1,visited,parent);
    }
    void assign(unordered_map <TreeNode*, TreeNode*> &parent, TreeNode *root, TreeNode *prev){
        if(root == nullptr) return;
        parent[root] = prev;
        assign(parent,root->left,root);
        assign(parent,root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector <int> ans;
        if(root == nullptr) return ans;
        TreeNode *p = nullptr;
        unordered_map <TreeNode*, TreeNode*> parent;
        assign(parent,root,p);
        unordered_map <TreeNode*, bool> visited;
        fission(ans,target,k,visited,parent);
        return ans;
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

    vector<int> ans;
    ans = distanceK(root, root->right, 1);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}