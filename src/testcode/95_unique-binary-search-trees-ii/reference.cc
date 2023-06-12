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
    vector<TreeNode*> generate(int left, int right){
        vector<TreeNode*> result;
        // 递归终止条件，注意这里需要将NULL返回
        if(left > right){
            result.push_back(nullptr);
            return result;
        }
        // 平衡二叉树的数据范围[left, right]
        // 以 i 为根节点，分别左右生成平衡二叉树
        for(int i =left; i<=right; i++){
            // 生成左树
            vector<TreeNode*> left_tree = generate(left, i-1);
            // 生成右树
            vector<TreeNode*> right_tree = generate(i+1, right);
            // 分别从左树，右树的vector中选取一个，作为当前root的左右树
            for(auto l_tree:left_tree){
                for(auto r_tree:right_tree){
                    TreeNode* root = new TreeNode(i);
                    root->left = l_tree;
                    root->right = r_tree;
                    // 将root压入result
                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        // 设置生成的二叉平衡书的范围
        auto result = generate(1,n);
        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}