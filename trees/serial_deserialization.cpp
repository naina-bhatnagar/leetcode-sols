#include <iostream>
#include <sstream>
#include <queue>
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

string serialize(TreeNode* root) {
    string ans = "";
    if(root == nullptr) return ans;
    queue <TreeNode*> q;
    q.push( root );
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode*curr = q.front();
            q.pop();
            if(curr == nullptr){
                ans += "null,";
                continue;
            }
            ans+=(to_string(curr->val));
            ans += ",";
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    ans.pop_back();
    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.length()==0) return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "null") curr->left = nullptr;
            else {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            getline(s, str, ',');
            if(str == "null") curr->right = nullptr;
            else {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
            
        }
    }
    return root;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    string ans = serialize(root);
    cout<<ans<<endl;

    return 0;
}