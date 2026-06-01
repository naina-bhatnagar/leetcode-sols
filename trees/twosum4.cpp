#include <iostream>
#include <vector>
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

void inorder(TreeNode* root, vector<int> &nums){
    if(root == nullptr) return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
    return;
}
bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inorder(root, nums);
    int n=nums.size(), st=0, end=n-1;
    int prev = 0;

    while(st>=0 && end<n && st<end){
        int curr = nums[st] + nums[end];
        if(curr == k) return true;
        else if(curr < k) st++;
        else end--;
        prev = curr;
    }
    return false;
}

int main(){
    return 0;
}