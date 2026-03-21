#include <iostream>
#include <vector>
#include <map>
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

void bottom(map <int,pair<int,int>> &m, int level, int line, Node *root){
    if(root==nullptr) return;
    if(m.find(line)==m.end() || level>m[line].first) m[line] = {level,root->data};
    bottom(m,level+1,line+1,root->right);
    bottom(m,level+1,line-1,root->left);
}
vector<int> bottomView(Node *root) {
    vector <int> ans;
    if(root == nullptr) return ans;
    map <int,pair<int,int>> m;
    bottom(m,0,0,root);
    
    for(auto el:m){
        ans.push_back(el.second.second);
    }
    return ans;
}

int main(){
    return 0;
}