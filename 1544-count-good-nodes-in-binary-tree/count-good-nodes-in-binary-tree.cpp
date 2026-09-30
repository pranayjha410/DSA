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
    int dfs(TreeNode* root, int maxSeen) {
        int count = 0;
        if (root == NULL) {
            return 0;
        }
        if (root->val >= maxSeen) {
            count = 1;
            maxSeen = root->val;
        }
        count += dfs(root->left, maxSeen);
        count += dfs(root->right, maxSeen);

        return count;
    }
    int goodNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return dfs( root, root->val);
    }
};