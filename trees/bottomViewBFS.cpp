#include <iostream>
#include <vector>
#include <map>
#include <queue>
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

vector<int> bottomView(Node *root) {
    vector<int> ans;
    if(root==nullptr) return ans;
    map<int,int>m;
    queue <pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        Node *curr = q.front().first;
        int l = q.front().second;
        q.pop();
        m[l] = curr->data;
        if(curr->left != nullptr) q.push({curr->left,l-1});
        if(curr->right != nullptr) q.push({curr->right,l+1});
    }
    for(auto el : m){
        ans.push_back(el.second);
    }
    return ans;
}

int main(){
    return 0;
}