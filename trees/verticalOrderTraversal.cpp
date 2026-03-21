#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
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

void trav(unordered_map <int,vector<pair<int,int>>> &m, int &minVal, int &maxVal, TreeNode *root, int level, int col){
    if(root == nullptr) return;
    m[col].push_back({level,root->val});
    minVal = min(minVal,col);
    maxVal = max(maxVal,col);
    trav(m,minVal,maxVal,root->left,level+1,col-1);
    trav(m,minVal,maxVal,root->right,level+1,col+1);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    unordered_map <int,vector<pair<int,int>>> m;
    int minVal = 0, maxVal = 0;
    trav(m,minVal,maxVal,root,0,0);

    for(int i=minVal; i<=maxVal; i++){
        sort(m[i].begin(),m[i].end());
        vector<int> curr;
        for(pair<int,int> p : m[i]){
            curr.push_back(p.second);
        }
        ans.push_back(curr);
    }
    return ans;
}

int main(){
    return 0;
}