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

int amountOfTime(TreeNode* root, int start) {
    int ans = -1;
    if(root == nullptr) return ans;
    unordered_map <TreeNode*, TreeNode*> parent;
    TreeNode *rotten = nullptr;
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode *p = q.front();
            if(p->val == start) rotten = p;
            q.pop();
            if(p->left != nullptr){
                parent[p->left] = p;
                q.push(p->left);
            }if(p->right != nullptr){
                parent[p->right] = p;
                q.push(p->right);
            }
        }
    }
    unordered_map <TreeNode*, bool> visited;
    q.push(rotten);
    visited[rotten] = true;
    while(!q.empty()){
        ans ++;
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left != nullptr && !visited[curr->left]){
                visited[curr->left] = true;
                q.push(curr->left);
            }if(curr->right != nullptr && !visited[curr->right]){
                visited[curr->right] = true;
                q.push(curr->right);
            }if(parent[curr] != nullptr && !visited[parent[curr]]){
                visited[parent[curr]] = true;
                q.push(parent[curr]);
            }
        }
    }

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

    cout<<amountOfTime(root,5)<<endl;

    return 0;
}