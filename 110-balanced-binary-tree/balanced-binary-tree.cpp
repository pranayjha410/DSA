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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftDepth = height(root->left);
        int rightDepth = height(root->right);

        int ans = max(leftDepth,rightDepth)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int leftDepth = height(root->left);
        int rightDepth = height(root->right);

        if (abs(leftDepth - rightDepth) > 1) {
            return false;
        }
       
       return isBalanced(root->left) && isBalanced(root->right);
    }
};