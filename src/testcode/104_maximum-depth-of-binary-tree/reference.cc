#include <iostream>
#include <vector>
#include <queue>

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
    int result;
    void serchTree(TreeNode* root,int Depth){
        if(root == nullptr){
            result= max(result, Depth);
            return;
        }

        serchTree(root->left, Depth+1);
        serchTree(root->right, Depth+1);
    }
    int maxDepth(TreeNode* root) {
        serchTree(root,0);
        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}