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
    TreeNode* pre;
    TreeNode* node1;
    TreeNode* node2;
    void searchTree(TreeNode* node){
        // 如果为空，直接返回
        if(node == nullptr){return;}
        // 中序遍历：左分支
        searchTree(node->left);
        // 中序遍历：根节点处理
        // 查找第一个异常节点
        if(pre!=nullptr && node1==nullptr && node->val < pre->val){
            node1 = pre;
        }
        // 查找第二个异常节点
        if(pre!=nullptr && node1 != nullptr && node->val < pre->val){
            node2 = node;
        }
            pre = node;
        // 中序遍历：右分支
        searchTree(node->right);
    }
    void recoverTree(TreeNode* root) {
        // 中序遍历搜索二叉搜索树
        // 中序遍历：左中右，因该是一个递增序列，方便查找异常点
        searchTree(root);
        // 交换两个节点的val值
        swap(node1->val, node2->val);
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}