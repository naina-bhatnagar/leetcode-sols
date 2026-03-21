#include <iostream>
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

vector<int> topView(Node *root) {
    vector <int> ans;
    unordered_map <int,int> m;
    int minVal = 0, maxVal = 0;
    queue <pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        root = q.front().first;
        int l = q.front().second;
        q.pop();
        if(root->left != nullptr) q.push({root->left,l-1});
        if(root->right != nullptr) q.push({root->right,l+1});
        if(m.find(l) == m.end()) m[l] = root->data;
        minVal = min(minVal,l);
        maxVal = max(maxVal,l);
    }
    for(int i=minVal; i<=maxVal;i++){
        ans.push_back(m[i]);
    }
    return ans;
}

int main(){
    return 0;
}