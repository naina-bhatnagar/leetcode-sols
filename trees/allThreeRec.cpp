#include <iostream>
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


// figure out preorder, inorder as well as postorder using a single recursive function

void constr(Node *root, vector <int> &preorder, vector<int> &inorder, vector<int>&postorder){
    if(root == nullptr) return;
    preorder.push_back(root->val);
    constr(root->left,preorder,inorder,postorder);
    inorder.push_back(root->val);
    constr(root->right,preorder,inorder,postorder);
    postorder.push_back(root->val);
}

int main(){
    return 0;
}