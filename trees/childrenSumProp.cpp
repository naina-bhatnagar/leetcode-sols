#include <iostream>
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

void converter(Node *root){
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr) return;
    int left = (root->left != nullptr ? root->left->val : 0);
    int right = (root->right != nullptr ? root->right->val : 0);
    if(left + right < root->val){
        if(root->left != nullptr) root->left->val = root->val;
        if(root->right != nullptr) root->right->val = root->val;
    }
    converter(root->left);
    converter(root->right);
    left = (root->left != nullptr ? root->left->val : 0);
    right = (root->right != nullptr ? root->right->val : 0);
    root->val = left+right;

}

int main(){
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(7);
    root->left->right = new Node(3);
    root->right->left = new Node(40);
    root->right->right = new Node(30);
    //              4 0
    //            /     \
    //          10       20
    //         /  \     /  \
    //        7    3   40   30

    converter(root);

    cout<<root->val<<endl;
    cout<<root->left->val<<endl;
    cout<<root->left->left->val<<endl;
    cout<<root->left->right->val<<endl;
    cout<<root->right->val<<endl;
    cout<<root->right->left->val<<endl;
    cout<<root->right->right->val<<endl;

    return 0;
}