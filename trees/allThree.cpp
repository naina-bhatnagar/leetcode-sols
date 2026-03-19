#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;

    Node(int v){
        val = v;
        left = right = nullptr;
    }
};

void constr(Node *root, vector <int> &preorder, vector<int> &inorder, vector<int>&postorder){
    if(root == nullptr) return;
    stack<pair<Node*,int>> s;
    s.push({root,1});
    while(!s.empty()){
        root = s.top().first;
        int &m = s.top().second;
        if(m==1){
            preorder.push_back(root->val);
            m++;
            if(root->left != nullptr) s.push({root->left,1});
        }else if(m==2){
            inorder.push_back(root->val);
            m++;
            if(root->right != nullptr) s.push({root->right,1});
        }else if(m==3){
            postorder.push_back(root->val);
            s.pop();
        }
    }
}

// figure out preorder, inorder as well as postorder in a single iteration using a stack (iteratively)
int main(){
    return 0;
}