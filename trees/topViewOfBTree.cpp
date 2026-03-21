#include <iostream>
#include <vector>
#include <unordered_map>
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

void trav(unordered_map <int,pair<int,int>> &m, int &minVal, int &maxVal, Node *root, int col, int level){
    if(root == nullptr) return;
    if (m.find(col) == m.end() || level < m[col].first) {
        m[col] = {level, root->data};
    }
    minVal = min(minVal,col);
    maxVal = max(maxVal,col);
    trav(m,minVal,maxVal,root->left,col-1,level+1);
    trav(m,minVal,maxVal,root->right,col+1,level+1);
}

vector<int> topView(Node *root) {
    vector<int> ans;
    unordered_map<int,pair<int,int>> m;
    int minVal = 0, maxVal = 0;
    trav(m,minVal,maxVal,root,0,0);

    for(int i=minVal; i<=maxVal; i++){
        ans.push_back(m[i].second);
    }
    return ans;
}

int main(){
    return 0;
}