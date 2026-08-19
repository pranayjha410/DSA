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
void inOrder(TreeNode* root, vector<int>&ans){
         if(root == NULL){
            return;
        }

       

        //1.left
        inOrder(root->left,ans);

         // 2.work
        ans.push_back(root->val);

        //3.right
        inOrder(root->right,ans);

    }
    vector<int> inorderTraversal(TreeNode* root) {
          vector<int>ans;
       inOrder(root,ans);
        return ans;
    }
};