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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, long long>> qu;
        qu.push({root, 0});
        long long ans = 0;

        while (!qu.empty()) {
            long long levelSize = qu.size();

            long long leftMost = qu.front().second;
            long long rightMost = qu.back().second;

            ans = max(ans, rightMost - leftMost + 1);

            while (levelSize--) {
                TreeNode* curr = qu.front().first;
                long long idx = qu.front().second;
                qu.pop();

                long long currIdx = idx - leftMost; // to avoid overall only

                if (curr->left != NULL) {
                    qu.push({curr->left, 2 * currIdx + 1});
                }

                if (curr->right != NULL) {
                    qu.push({curr->right, 2 * currIdx + 2});
                }
            }
        }
        return ans;
    }
};