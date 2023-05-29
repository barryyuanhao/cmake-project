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
        // 中序遍历： 左-中-右
        // 检查是否为空二叉树
        if(node == nullptr){return;}
        // 遍历左分支
        inorderTraversal(node->left);
        // 根节点
        result.push_back(node->val);
        // 遍历右分支
        inorderTraversal(node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        binaryTree(root);
        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}