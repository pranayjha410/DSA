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
public: vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
       
        if(root == NULL){
            return ans;
        }

        // 1.work
        ans.push_back(root->val);

        //2.left
        preorderTraversal(root->left);

        //3.right
        preorderTraversal(root->right);

        return ans;
    }
};