#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int v){
        data = v;
        left = right = nullptr;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
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