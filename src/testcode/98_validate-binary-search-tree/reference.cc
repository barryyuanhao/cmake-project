#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a):val(a),left(nullptr),right(nullptr){}
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
    // 采用中序遍历，所有的节点都满足前一个节点值小于后一个节点值
    // pre用于动态记录前一个节点值
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){return true;}
        // 左
        if(!isValidBST(root->left)){return false;}
        // 中
        if(pre && root->val <= pre->val){return false;}
        pre = root;
        // 右
        if(!isValidBST(root->right)){return false;}

        return true;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}