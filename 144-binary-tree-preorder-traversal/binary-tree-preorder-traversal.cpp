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
    void preOrder(TreeNode* root, vector<int>&ans){
         if(root == NULL){
            return;
        }

        // 1.work
        ans.push_back(root->val);

        //2.left
        preOrder(root->left,ans);

        //3.right
        preOrder(root->right,ans);

    }
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int>ans;
       preOrder(root,ans);
        return ans;
    }
};