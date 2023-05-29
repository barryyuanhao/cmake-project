#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    void binaryTree(TreeNode* node){
        // 前序遍历： 中-左-右
        if(node == nullptr){return;}
        // 根节点
        result.push_back(node->val);
        // 遍历左分支
        preorderTraversal(node->left);
        // 遍历右分支
        preorderTraversal(node->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        binaryTree(root);
        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}