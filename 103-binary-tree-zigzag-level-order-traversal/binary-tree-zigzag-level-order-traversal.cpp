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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        qu.push(root);
        int level =0;
        while (!qu.empty()) {
            int levelSize = qu.size();
            vector<int> currentLevel;

            while (levelSize--) {
                TreeNode* curr = qu.front();
                qu.pop();
                currentLevel.push_back(curr->val);

                if (curr->left != NULL) {
                    qu.push(curr->left);
                }
                if (curr->right != NULL) {
                    qu.push(curr->right);
                }
            }
            if(level % 2 == 1){
                reverse(currentLevel.begin(),currentLevel.end());
            }
            ans.push_back(currentLevel);
            level++;
        }
        return ans;
    }
};