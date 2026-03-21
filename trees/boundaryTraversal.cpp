#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(Node* root){
    return (root->left == nullptr && root->right == nullptr);
}
void addleaf(vector<int> &ans, Node *root){
    if(root == nullptr) return;
    if(isLeaf(root)) ans.push_back(root->data);
    addleaf(ans,root->left);
    addleaf(ans,root->right);
}
vector<int> boundaryTraversal(Node *root) {
    vector <int> ans;
    if (!isLeaf(root)) ans.push_back(root->data);
    Node *curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left != nullptr) curr = curr->left;
        else curr = curr->right;
    }
    addleaf(ans, root);
    curr = root->right;
    vector<int>rev;
    while(curr){
        if(!isLeaf(curr)) rev.push_back(curr->data);
        if(curr->right != nullptr) curr = curr->right;
        else curr = curr->left;
    }
    reverse(rev.begin(),rev.end());
    for(int el : rev){
        ans.push_back(el);
    }
    return ans;
}

int main(){
    return 0;
}