#include <iostream>
#include <vector>
#include <algorithm>
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
    // 本题与二叉树的层序遍历相同,只是在每一轮的循环中增加一个flag,判断是否需要进行反转
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 存储最终的结果
        vector<vector<int>> result;
        // 队列,用于顺序存储压入的节点
        queue<TreeNode*> que;
        if(root != nullptr){
            que.push(root);
        }

        // flag用于循环控制反转,
        bool flag = false;
        while(!que.empty()){
            int size=que.size();
            vector<int> path;
            for(int i=0; i< size; i++){
                TreeNode* temp = que.front();
                que.pop();
                path.push_back(temp->val);
                if(temp->left != nullptr){que.push(temp->left);}
                if(temp->right != nullptr){que.push(temp->right);}
            }
            // 一层反转,一层正序
            if(flag){
                reverse(path.begin(), path.end());
            }
            flag = flag ? false:true;
            result.push_back(path);
        }

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}