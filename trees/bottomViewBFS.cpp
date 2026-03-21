#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int,int>m;
    int minVal = 0, maxVal = 0;
    queue <pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        Node *curr = q.front().first;
        int l = q.front().second;
        q.pop();
        m[l] = curr->data;
        minVal = min(minVal,l);
        maxVal = max(maxVal,l);
        if(curr->left != nullptr) q.push({curr->left,l-1});
        if(curr->right != nullptr) q.push({curr->right,l+1});
    }
    for(int i=minVal;i<=maxVal;i++){
        ans.push_back(m[i]);
    }
    return ans;
}

int main(){
    return 0;
}