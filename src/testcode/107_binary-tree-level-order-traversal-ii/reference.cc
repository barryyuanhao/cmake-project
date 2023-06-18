#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root != nullptr){que.push(root);}

        while(!que.empty()){
            vector<int> path;
            int size = que.size();
            for(int i=0; i< size; i++){
                TreeNode* temp = que.front();
                que.pop();
                path.push_back(temp->val);
                if(temp->left != nullptr){que.push(temp->left);}
                if(temp->right != nullptr){que.push(temp->right);}
            }

            result.push_back(path);
        }

        //本题与自上而下的层序遍历的区别就是最后增加反转
        reverse(result.begin(), result.end());

        return result;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}