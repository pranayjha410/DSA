/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftDepth = dfs(root->left);
        if (leftDepth == -1)
            return -1;

        int rightDepth = dfs(root->right);
        if (rightDepth == -1)
            return -1;

        if (abs(leftDepth - rightDepth) > 1) {
            return -1;
        }

        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode* root) { return dfs(root) != -1; }
};