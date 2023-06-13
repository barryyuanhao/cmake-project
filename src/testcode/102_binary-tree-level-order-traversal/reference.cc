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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        // FIFO先进先出动态存入节点，
        // 每一轮while循环是计算的当前层的size，
        queue<TreeNode*> que;
        if(root){
            que.push(root);
        }

        while(!que.empty()){
            // 计算当前轮的size,在执行过程中动态存入下一轮的子节点
            int size = que.size();
            vector<int> path;
            for(int i=0; i< size; i++){
                TreeNode* temp = que.front();
                que.pop();
                path.push_back(temp->val);
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            result.push_back(path);
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}